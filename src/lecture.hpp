#ifndef LECTURE_H
#define LECTURE_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>


//chercher directement les position; verifier ACGT ??

/**
 * Classe pour lire les fichiers FASTA contenant les séquences d'ADN.
 */
class LiseurFasta {
public:
    /**
     * Constructeur. Prend en argument les indices de la séquence contenant les
     * bases d'intérêt de chaque allèle.
     */
    LiseurFasta(std::vector<size_t> markers_);

    /**
     * Consomme la source et stocke et les allèles et fréquences respectives.
     */
    void lire(std::istream& source);

    /**
     * Lit le fichier FASTA dont le chemin est donné.
     */
    void lire_fichier(const std::string& chemin);

    /**
     * Renvoie un tableau des fréquences de chaque allèles, dans le même ordre
     * que alleles_seq().
     */
    std::vector<double> frequence_alleles() const;

    /**
     * Renvoie un tableau des allèles sous forme de texte. Tous les allèles ont
     * la même longueur, c'est-à-dire le nombre de marqueurs donnés au
     * constructeur.
     */
    std::vector<std::string> alleles_seq() const;
  
private :
    std::vector<size_t> markers;
    std::map<std::vector<char>, unsigned int> alleles;
    unsigned int total_occurences = 0;
};

#endif

