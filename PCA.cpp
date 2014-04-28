#include <iostream>
#include <vector>
#include <math.h>
#include "PCA.h"

using namespace std; 

PCA::PCA() {

} 

Eigen PCA::eignvalues()
{
	return this->values;
}

std::vector<Vector> PCA::generate(std::size_t x, std::size_t y) {

	std::vector<Vector> temp(x, Vector(y, 0.0));
	for(unsigned i=0; (i < 100); i++)
	{
		for(unsigned j=0; (j < 2); j++)
		{
			temp[i][j] = rand() % 100;
		}
	}
	return temp;
} 
void PCA::eig2() {

	/* Eigen 
	   Use this method if solving the Eigen values for a
	   2x2 symmetric matric 
	*/

	// return Coveriance matrix 

	std::vector<Vector> cov_matrix = this->cov(); 

	// Store each of the linear values..

	float a = cov_matrix[0][0]; 
	float b = cov_matrix[1][0]; 
	float c = cov_matrix[1][1]; 

	// Calculate the determinate 

	float d = (a + c) * (a + c) - 4 *(a*c-b*b);

	if(d < 0)
	{
		d = 0; 
	}

	// Assign the Eign values 

	values.lambda1 = (a+c+sqrt(d))/2;
	values.lambda2 = (a+c-sqrt(d))/2;
 	
 	for(unsigned i=0; (i < cov_matrix.size()); i++)
	{
		for(unsigned j=0; (j < cov_matrix[i].size()); j++)
		{
			std::cout << cov_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
std::vector<Vector> PCA::cov() {

	return c->transform();
} 