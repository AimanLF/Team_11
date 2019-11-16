#include <vector>
#include <iostream>
#include "lecture.hpp"
#include <tclap/CmdLine.h>
#include "population.hpp"

using namespace TCLAP;

int main(int argc, char **argv){
	
	CmdLine cmd("TCLAP Genetique Populations");
	
	ValueArg<std::string> fichier("f", "fichier_fasta", "nom du fichier fasta", false, "defaut" , "string" );
	cmd.add(fichier);
	
	ValueArg<int> popu ("N", "taille_population", "Nombre d'individus dans la population", false, 100, "int");
    cmd.add(popu);
    
    ValueArg<unsigned int> gen ("T", "nombre_generations", "combien de generations differentes ", false, 10 , "unsigned int");
    cmd.add(gen);
    
    ValueArg<unsigned int> al ("A", "nombre_allèles", "Nombre d'allèles différents représentés", false, 2, "unsigned int");
    cmd.add(al);
   
    MultiArg<double> frequences ("F", "frequences_initiales", "les frequences initiales des allèles", false, "double");
    cmd.add(frequences);
   
    ValueArg<unsigned int> simulations ("R", "nombre_simulation", "Nombre de simulations differentes", false, 500 , "unsigned int");
   cmd.add(simulations);
	
	 

	MultiArg<size_t> marqueurs ("m", "marqueurs", "liste de marqueurs correspondant au fichier fourni" , false, "size_t" );
	cmd.add(marqueurs);
	
	 
	
	 
	cmd.parse(argc, argv);
	int pop (popu.getValue()); 
    unsigned int generations (gen.getValue()); 
    unsigned int alleles (al.getValue()); 
    std::vector<double> freq = frequences.getValue(); 
    unsigned int sim (simulations.getValue()); 
    std::string fasta (fichier.getValue()); 
	std::vector<size_t> liste_marqueurs = marqueurs.getValue();
	LiseurFasta lecteur(liste_marqueurs);
	
	if (fichier.isSet() and marqueurs.isSet() ) {
		try {
			lecteur.lire_fichier(fasta);
		} catch (const std::exception& e) {
			std::cerr << "Erreur : " << e.what() << std::endl;
		}
		Population b(fasta, liste_marqueurs); 
	} else {
  
		try {
		Population a (pop, alleles, freq); 
		} catch (std::string &e) {
			std::cout << e << std::endl; 
        }
	}

	
        

	return 0;
}
