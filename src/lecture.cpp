#include "lecture.hpp"
#include <ctype.h>
#include <iostream>


//chercher directement les position; verifier ACGT ??
LiseurFasta::LiseurFasta(std::vector<size_t> markers_)
    : markers(markers_)
{
    std::sort(markers.begin(), markers.end());
}


void LiseurFasta::lire(std::istream& source) {
    char ch;

    while (true) {
        if (!source.get(ch)) {
            return;
        }

        if (ch == '\n') {
            continue;
        } if (ch == '>') {
            break;
        }

        throw std::invalid_argument("Charactère inattendu '" + std::string(1, ch) + "', attendu '>'");
    }


    while (true) {
        std::string nom;
        std::getline(source, nom);

        std::vector<char> allele;
        size_t indice_char(0);
        size_t marker_index(0);
        bool nouvelle_ligne(true);

        bool eof;

        while (!(eof = !source.get(ch))) {
            if (ch == '\n') {
                nouvelle_ligne = true;
                continue;
            }

            if (nouvelle_ligne && ch == '>') {
                break;
            }

            char ch_maj = toupper(ch);

            if (ch_maj != 'A' && ch_maj != 'C' && ch_maj != 'T' && ch_maj != 'G') {
                throw std::invalid_argument("Charactère inattendu '" + std::string(1, ch)
                        + "' à l'indice " + std::to_string(indice_char)
                        + " dans la séquence '" + nom + "', attendu 'A', 'C', 'T' ou 'G'");
            }

            if (marker_index < markers.size() && indice_char == markers[marker_index]) {
                allele.push_back(ch_maj);
                marker_index++;
            }

            indice_char++;
            nouvelle_ligne = false;
        }


        if (marker_index != markers.size()) {
            throw std::invalid_argument("Nombre insuffisant de marqueurs pour la séquence '"
                    + nom + "' de " + std::to_string(indice_char) + " bases, attendues au moins "
                    + std::to_string(markers.back() + 1) + " bases");
        }

        if (alleles.count(allele) == 0) {
            alleles[allele] = 1; // le crée automatiquement
        } else {
            alleles[allele] += 1;
        }

        total_occurences += 1;

        if (eof) {
            break;
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
