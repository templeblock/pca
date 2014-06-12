#include <iostream>
#include <vector>
#include <array> 
#include <algorithm>
#include "../src/PCA.h"

void printValue(double val)
{
    std::cout << val << " ";
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

    // Firstly, given the 2x2 matrix
    std::vector<std::vector<double> > data = {

	    {0, 1},
	    {2, 4},
	
     };

     // Call the PCA mathod. Use iterators, 
     // avoid passing vector to function 
     PCA pca(std::begin(data), std::end(data)); 
     // Return the Eigen values and Eigen vectors of the input
     // Matrix, ready to perform the PCA analysis of the data. 
     std::vector<std::vector<double> > eigens = pca.getEigen();

     std::cout << "Eigen Values: " << std::endl;
     std::for_each(eigens[0].begin(), eigens[0].end(), printValue); 

     std::cout << std::endl;
     
     std::cout << "Eigen Vectors" << std::endl;
     std::for_each(eigens[1].begin(), eigens[1].end(), printValue); 

     std::cout << std::endl; 
    
     return 0;

}
