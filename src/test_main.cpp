#include <gtest/gtest.h>

#include "aleatoire.hpp"
#include "lecture.hpp"


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


TEST(TestLecture, SequenceAlleles) {
    std::stringstream source;
    source << ">foo\nAGGTCAC\n>bar\nAGATCCGAT\n>qux\nCGG\nATCAGCTG";

    LiseurFasta lecteur({2, 5});
    lecteur.lire(source);

    std::vector<std::string> alleles = lecteur.alleles_seq();

    EXPECT_EQ(std::set<std::string>(alleles.begin(), alleles.end()),
            std::set<std::string>({"GA", "AC", "GC"}));

    EXPECT_EQ(alleles.size(), lecteur.frequence_alleles().size());
}

TEST(TestLecture, Frequences) {
    std::stringstream source;
    source << ">sample1\nTCTTCATTCTCTCGCTTTC\n>sample2\nCCCACGTAACATGTCTTGA\n>sample3\nCATCCCTGAAAGTGAACAC\n>sample4\nCCATTTTTTAGTCTTTTCG\n>sample5\nGTCTGAGAACACCCCCTTT";

    LiseurFasta lecteur({5, 14});
    lecteur.lire(source);

    std::map<std::string, double> frequences_attendues = {
        {"AC", 2.0 / 5.0},
        {"GC", 1.0 / 5.0},
        {"CA", 1.0 / 5.0},
        {"TT", 1.0 / 5.0}
    };

    std::vector<double> frequences = lecteur.frequence_alleles();
    std::vector<std::string> alleles = lecteur.alleles_seq();

    for (size_t indice = 0; indice < alleles.size(); indice++) {
        EXPECT_EQ(frequences[indice], frequences_attendues[alleles[indice]]);
    }
}

TEST(TestLecture, MiseEnPage) {
    std::stringstream source;
    source << "\n\n>>>>KY549441.1 carboxylase/oxygenase large subunit (RUBISCO) gene, partial cds; chloroplast\n\nAGGTCG\nAGCGAATT\n\nAGGTA\n\n\n>KY549441.1\nAGGCTA";

    LiseurFasta lecteur({});
    lecteur.lire(source);
}

TEST(TestLecture, SourceVide) {
    std::stringstream source;
    source << "\n\n";

    LiseurFasta lecteur({35, 42, 96});
    lecteur.lire(source);
}

TEST(TestLecture, SequenceIncorrecte) {
    std::stringstream source;
    source << ">foo\nAGGCTAAGrCTAGG";

    LiseurFasta lecteur({});
    EXPECT_THROW(lecteur.lire(source), std::invalid_argument);
}

TEST(TestLecture, MarqueurManquant) {
    std::stringstream source;
    source << ">foo\nAGTTC";

    LiseurFasta lecteur({0, 3, 9});
    EXPECT_THROW(lecteur.lire(source), std::invalid_argument);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

