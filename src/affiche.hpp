
#ifndef AFFICHE_H
#define AFFICHE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
/** Afficheur prend en attribut un size_t : le nombre R de simulations
 */
class Afficheur {
public:
    Afficheur(size_t nb_simul_);
    /** affiche_seq prend en attribut la liste d'alleles à afficher: un tableau de string
     * et la simulation actuelle.
     * /
     * @param seq_alleles
     * @param simul
     */
    void affiche_seq(std::vector<std::string> const& seq_alleles, size_t simul);
     /** affiche_freq prend en attribut la liste des fréquences à afficher: un tableau de double
     * et la simulation actuelle.
      * /
      * @param freq_alleles
      * @param simul
      */
    void affiche_freq(std::vector<double> const& freq_alleles, size_t simul);
private :
    int compteur;
    size_t nb_simul;
};

#endif
