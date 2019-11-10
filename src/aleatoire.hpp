#pragma once

#include <vector>
#include <algorithm>
#include <random>

class Aleatoire{
	
	public : 
	
	Aleatoire (); 
	std :: vector<double> multinomiale(int N, std :: vector<double> effectif_allele);
	
	private : 
	std::mt19937 rng;

	
	
	
	
	
	};

