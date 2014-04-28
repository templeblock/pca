#include <iostream>
#include <vector>
#include <math.h>
#include "PCA.h"

using namespace std; 

PCA::PCA() {

} 

void PCA::eig2() {

	/*
	
		Eign values and vectors 

		-- Tested on a 2x2 matrix, 

	*/ 

	std::vector<Vector> cov_matrix = this->cov(); 	

	float a = cov_matrix[0][0]; 
	float b = cov_matrix[1][0];
	float c = cov_matrix[1][1];

	//std::cout << a << std::endl;
	//std::cout << a << " " << b << " " << c << std::endl;
	
	float d = (a+c)*(a+c)-4*(a*c-b*b);
	//float d = (a+b)*(a+b)-4*(a*b-c*c);
	d = sqrt(d);
	
	float l0 = (a+c+d)/2;
    float l1 = (a+c-d)/2;


	std::cout << l0 << std::endl;//<< std::endl << l1;
	std::cout << l1 << std::endl;

	//std::cout << c << std::endl;
	for(unsigned i=0; (i < cov_matrix.size()); i++)
	{
		for(unsigned j=0; (j < cov_matrix[i].size()); j++)
		{
			//std::cout << cov_matrix[i][j] << " ";
		}
		//std::cout << std::endl;
	}

}
std::vector<Vector> PCA::cov() {

	return c->transform();
} 