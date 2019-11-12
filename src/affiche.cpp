
#include "affiche.hpp"
#include <iomanip>

Afficheur::Afficheur(size_t nb_simul_)
    :nb_simul(nb_simul_ - 1)
{
    compteur = 0;
}

void Afficheur::affiche_seq(std::vector<std::string> const& seq_alleles, size_t simul){
    if(simul == 0) std::cout << std::setw(10);

    size_t t(seq_alleles.size() - 1);
    for (size_t j = 0; j < t; ++j) {
        std::cout << seq_alleles[j] << '|';
    }
    std::cout << seq_alleles[t]<<std::setw(15);
}

void Afficheur::affiche_freq(std::vector<double> const& freq_alleles, size_t simul) {
    if(simul == 0) {
        std::cout << compteur << std::setw(10);
        ++compteur;
    }
    size_t t(freq_alleles.size()-1);
    for(size_t i=0; i < t ; ++i){
        std::cout<<freq_alleles[i]<<'|';
    }
    std::cout<<freq_alleles[t];
    if(simul < nb_simul) std::cout<< std::setw(10);

    if(simul == nb_simul) std::cout<<std::endl;
    //à la fin, comme la première ligne est 0
}
