#include <string>
#include <map>
class Population{
	public:
	Population(long int t);
	void ajout_allele(std::string sequence, double frequence);
	
	private:
	long int taille;
	std::map<std::string, double> alleles;
	
	
};
