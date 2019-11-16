#include "population.hpp"
#include "lecture.hpp"

Population::Population (int t, unsigned int a, std::vector<double> f)
 {
	if (t <= 0) throw std::string ("Erreur! La taille de la population est inférieure à 0, le programme s'arrête.");
	if (a <= 0) throw(std::string ("le nombre d'allèles doit etre positif"));
    if ( a =! f.size()) throw(std::string("le nombre de fréquences doit correspondre au nombre d'allèles"));
		for ( unsigned int i(1) ; i<= a ; ++ i ) {
			std::string al ("allele "); 
			ajout_allele( al + std::to_string (i)  , f[i]);
			
		}
		
	}
	
Population::Population ( std::string fich , std::vector<size_t> m) {
	LiseurFasta lecteur(m);
	
	 try {
        lecteur.lire_fichier(fich);
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    
    std::vector<double>freq (lecteur.frequence_alleles()); 
    std::vector<std::string> a (lecteur.alleles_seq()); 
    for (size_t i(0) ; i<freq.size() ; ++ i ) {
		ajout_allele( a[i] , freq[i] ); 
	}
  }  
		
	
	
	
void Population::ajout_allele(std::string sequence, double frequence){
	alleles.insert({sequence, frequence});
}
