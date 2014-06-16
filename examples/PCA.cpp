#include <iostream>
#include <vector>
#include <array> 
#include <algorithm>
#include "../src/PCA.h"

void printValue(double val)
{
    std::cout << val << " ";
}

void printData(std::vector<std::vector<double> > &data)
{
    for(auto& rows : data) {
	for(auto & cols : rows) {
	   std::cout << cols << " ";
	}
	std::cout << std::endl;
    }
}

int main()
{
    /*
	Given firstly is an example
	of calculating the Eigenvalues
	and Eigenvectors of a basic 2x2 matrix. 

	Following on from this, presented is
	an example for calculating and determining
	the Eigenvalues and Eigenvectors of a 3x3 and 4x4
     */ 
	
    // Given a 2x2 matrix, compute the PCA of this:
    std::vector<std::vector<double> > input1 = {
	{1, 2},
	{3, 4},
	{5, 6}
    };

    std::cout << "Input Matrix: " << std::endl;
    printData(input1);
    std::cout << std::endl; 

    PCA pca(std::begin(input1), std::end(input1)); 
	
    std::cout << "Cov Matrix: " << std::endl;
    
    std::vector<std::vector<double> > cov_matrix1 = pca.cov();
    printData(cov_matrix1);

    std::vector<std::vector<double> > eigen_values = pca.getEigen(); 
    std::cout << "Eigen Values: " << std::endl;
    std::for_each(eigen_values[0].begin(), eigen_values[0].end(), printValue); 
    
    std::cout <<std::endl << "Eigen Vectors: " << std::endl;
    std::for_each(eigen_values[1].begin(), eigen_values[1].end(), printValue);
   
    return 0;
}
