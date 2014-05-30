#include <iostream>
#include <vector>
#include <array> 
#include <algorithm>
#include "../src/PCA.h"


int main()
{
    std::vector<std::vector<double> > data = {

	   {1, 2},
	   {3, 4}
     };

     PCA pca(std::begin(data), std::end(data)); 
     std::vector<std::vector<double> > eigens = pca.getEigen();

     std::cout << "Eigen Values: " << std::endl;
     std::for_each(eigens[0].begin(), eigens[0].end(), [](double var){

        std::cout << "(" << var << ")"; 

     });
     std::cout << std::endl;
     
     std::cout << "Eigen Vectors" << std::endl;
     std::for_each(eigens[1].begin(), eigens[1].end(), [] (double var){

        std::cout << "(" << var << ")";

     });
     std::cout << std::endl; 

     /* Get the Coeffs */ 

     

     return 0;

}
