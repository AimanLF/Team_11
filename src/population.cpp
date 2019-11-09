#include "population.hpp"

Population::Population(long int t)
	: taille(t) 
	{if (taille <= 0) {
		throw std::runtime_error("Erreur! La taille de la population est inférieure à 0, le programme s'arrête.");
		} //try et catch à faire dans main (ou lecture peut être)
	} 
	
void Population::ajout_allele(std::string sequence, double frequence){
	alleles.insert({sequence, frequence});
}
