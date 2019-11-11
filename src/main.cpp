#include <vector>
#include <iostream>
#include "lecture.hpp"
#include <tclap/CmdLine.h>

using namespace TCLAP;

int main(int argc, char **argv){
	
	CmdLine cmd("TCLAP Genetique Populations");
	 
	ValueArg<std::string> fichier("f", "fichier", "nom du fichier fasta", true, "defaut" , "string" );
	cmd.add(fichier);
	MultiArg<size_t> marqueurs ("m", "marqueurs", "liste de marqueurs correspondant au fichier fourni" , false, "size_t" );
	cmd.add(marqueurs);
	
	cmd.parse(argc, argv);
	
	std::vector<size_t> liste_marqueurs = marqueurs.getValue();
	LiseurFasta lecteur(liste_marqueurs);

    try {
        lecteur.lire_fichier(fichier.getValue());
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

	return 0;
}
