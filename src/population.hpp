#include <string>
#include <map>
#include <vector>

class Population{
	public:
	Population( int t, unsigned int a, std::vector<double> f);
	Population ( std::string fich , std::vector<size_t> m); 
	void ajout_allele(std::string sequence, double frequence);
	
	private:
	std::map<std::string, double> alleles;
	
	
};
