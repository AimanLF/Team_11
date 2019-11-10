#ifndef LECTURE_H
#define LECTURE_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>


//chercher directement les position; verifier ACGT ??

class LiseurFasta {
public:
    LiseurFasta(std::vector<size_t> markers_ = { 2, 4 });
    void lire(std::istream& source);
    //tableau de fréquences
    std::vector<double> frequence_alleles() const;
    //tableau des séquences
    std::vector<std::string> alleles_seq() const;
  
private :
    std::vector<size_t> markers;
    std::map<std::vector<char>, unsigned int> alleles;
    unsigned int total_occurences = 0;
};

#endif

