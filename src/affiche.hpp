
#ifndef AFFICHE_H
#define AFFICHE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

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

    /** affiche_seq ecrivant dans un fichier texte
     *
     * @param seq_alleles
     * @param simul
     */
    void affiche_seq_fichier(std::vector<std::string> const& seq_alleles, size_t simul);

    /** affiche_freq ecrivant dans un fichier texte
     *
     * @param freq_alleles
     * @param simul
     */
    void affiche_freq_fichier(std::vector<double> const& freq_alleles, size_t simul);

private :
    int compteur;
    int compteur_fichier;
    size_t nb_simul;
    std::string nomFichier;
    std::ofstream monFlux;
};

#endif
