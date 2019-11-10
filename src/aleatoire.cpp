#include <iostream>
#include "aleatoire.hpp"


Aleatoire::Aleatoire () {
    
        std::random_device rd;
        rng = std::mt19937(rd());
}


std :: vector<double> Aleatoire :: multinomiale(int N, std :: vector<double> effectif_allele){

    std :: vector<double> nouveaux_effectifs(effectif_allele.size(), 0);

    int k(0);
    int taille(N);

    for (size_t i(0); i < effectif_allele.size() - 1; ++i) {
        std :: binomial_distribution<int> distribution(N + k, (double) effectif_allele[i]/taille);
        nouveaux_effectifs[i] = distribution(rng);

        k -= nouveaux_effectifs[i];
        taille -= effectif_allele[i];
    }

    nouveaux_effectifs[nouveaux_effectifs.size() - 1] = N + k;


    return nouveaux_effectifs;
}

