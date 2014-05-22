#include <iostream>
#include <vector>
#include "../src/PCA.h"


int main()
{
    std::vector<std::vector<double> > data = {

	    {-4, -1},
	    {0, 1}, 
	    {2, 3},
	    {4, 5},
	    {6, 7}
     }

     PCA pca(std::begin(data), std::end(data)); 
 
   
	/*std::vector<std::vector<double> > data_2 = { 
		{-2, -1}, {1,2},
	};
	
	PCA pca(std::begin(data_2), std::end(data_2));
	
	std::vector<std::vector<double> > eigens = pca.getEigen();
        */

	/*for(std::size_t i = 0; (i < eigens.size()); i++)
	{
	   for(std::size_t j=0; (j < eigens[i].size()); j++)
	   {
		std::cout << eigens[i][j]; 
	   }

	  std::cout << std::endl;
	}
	*/
	return 0;

}
