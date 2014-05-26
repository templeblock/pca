#include <iostream>
#include <vector>
#include <array> 
#include "../src/PCA.h"


int main()
{
    std::vector<std::vector<double> > data = {

	    {-4, -1},
	    {0, 1}, 
	    {2, 3},
	    {4, 5},
	    {6, 7}
     };

     PCA pca(std::begin(data), std::end(data)); 
     std::vector<std::vector<double> > eigens = pca.getEigen();

     for(std::size_t i=0; (i < eigens.size()); i++)
     {
	for(std::size_t j=0; (j < eigens[i].size()); j++)
	{
	    std::cout << eigens[i][j] << " "; 
	}
	std::cout << std::endl;
     }

     std::array<std::array<double, 2>, 5> arr = {{
	{-4, -1}, 
	{0, 1},
	{2, 3}, 
	{4, 5},
	{6, 7}
     }};
     
     PCA pcaArray(arr.begin(), arr.end()); 
     //std::vector<std::vector<double> > eigenArray = pcaArray.getEigen();
    /* for(std::size_t i=0; (i < eigensArray.size()); i++)
     {
	for(std::size_t j=0; (j < eigensArray[i].size()); j++)
	{
	   std::cout << eigensArray[i][j] << " "; 
	}
        std::cout << std::endl;
     }
    */

     return 0;

}
