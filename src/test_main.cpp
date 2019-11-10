#include <gtest/gtest.h>
#include "aleatoire.hpp"


TEST (testAleatoire, multinomialDistribution) {
	int N(18); 
	Aleatoire a; 
	std::vector<double>effectifs{1,3,5,9}; 
	std::vector<double> nouveaux_effectifs (a.multinomiale(N, effectifs)) ; 
	double freq_tot (0);  
	for (auto effectif : nouveaux_effectifs) {
		freq_tot += effectif/N; 
	}
	
	EXPECT_EQ(1, freq_tot); 
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

