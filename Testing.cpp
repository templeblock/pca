#include <iostream>
#include <vector> 
#include "src/PCA.h"

using namespace std;

std::vector<double> eye(std::size_t n, std::size_t nn)
{
    /* This method generates 
       the identity matrix 
       of (nxn) where ones
       are placed on the main
       diagonal and zeros
       on the rest. 
    */ 
   
    std::vector<double> diag(n*nn);
     
    for(std::size_t i = 0; (i < n); i++)
    {
	for(std::size_t j=0; (j < nn); j++)
	{
	    if(i == j)
	      diag[i*nn+j] = 1;
	   	//std::cout << "1";
            else
	    diag[i*nn+j] = 0;
	    //std::cout << diag[i*nn+j] << " "; 	  
	}
	//std::cout << std::endl;
    }
    return diag; 
}

int main() {
  
  std::vector<std::vector<double> > vals = {

	{1, 2, 1},
	{5, 41, 2},
	{1, 5, 1}
  };
  

  // Carry out PCA analysis of the data 
 // 1) Calculating the coveriance matrix
 // 2) Calculating the Eigenvalues and Eigenvectors 
 	

  // How you can use this library for much more
  // than just PCA -> EVEN THOUGH IT IS CALLED PCA. 

// First we're not going to calculate the Eigenvalues and Eigenvectors, but infact the Coveriance matrix. 

  PCA pca(std::begin(vals), std::end(vals));
	
  //std::vector<std::vector<double> > cov_matrix = pca.cov();
  //std::cout << vals.size();
  std::vector<double> identity_matrix = eye(vals.size(), vals[0].size()); 
  
  for(std::size_t i=0; (i < 3); i++)
  {
     for(std::size_t j=0; (j < vals[0].size()); j++)
     {
	std::cout << identity_matrix[i*3+j] << " ";
     }
     std::cout << std::endl;
  }


 
  

  return 0; 
}
