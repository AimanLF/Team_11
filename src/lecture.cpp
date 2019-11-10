#include "lecture.hpp"
#include <iostream>


//chercher directement les position; verifier ACGT ??
LiseurFasta::LiseurFasta(std::vector<size_t> markers_)
	: markers(markers_)
	{
		std::sort(markers.begin(), markers.end());
	}
    
void LiseurFasta::lire(std::istream& source) {
    char ch;

    while (source.get(ch)) {
      if (ch == '>') {
        std::string name;
        std::getline(source, name);

        char ch;

        size_t char_index(0);
        size_t marker_index(0);

        std::vector<char> allele;

        while (source.get(ch)) {
          if (ch == '>') {
            source.unget();
            break;
          }

          if (ch == '\n') {
            continue;
          }

          if (ch != 'A' && ch != 'C' && ch != 'T' && ch != 'G') {
            std::string message("Unexpected token '");
            message.push_back(ch);
            message += "', expected 'A', 'C', 'T' or 'G'";

            throw std::invalid_argument(message);
          }

          if (marker_index == markers.size()) {
            continue;
          }

          if (char_index == markers[marker_index]) {
            allele.push_back(ch);
            marker_index += 1;
          }

          char_index += 1;
        }

        if (marker_index != markers.size()) {
          throw std::invalid_argument("Unexpected token, expected 'A', 'C', 'T' or 'G'");
        }

		if(alleles.count(allele) == 0){
			alleles[allele] = 1; //le cree automatiquement
		} else {
			alleles[allele] += 1;
		}
		
		total_occurences += 1;

      } else if (ch != '\n') {
        std::string message("Unexpected token '");
        message.push_back(ch);
        message += "', expected '\\n' or '>'";

        throw std::invalid_argument(message);
      }
    }
}

std::vector<double> LiseurFasta::frequence_alleles() const{
    std::vector<double> freq;
    for(auto allele : alleles){
        freq.push_back((double) allele.second / total_occurences);
    }
    return freq;
}

std::vector<std::string> LiseurFasta::alleles_seq() const {
    std::vector<std::string>alleles_seq_;
    for(auto allele : alleles){
        alleles_seq_.push_back(std::string(allele.first.begin(), allele.first.end()));
    }
    return alleles_seq_;
}
