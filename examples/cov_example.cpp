#include <iostream>
#include <vector>
#include "../src/Cov.h"

using namespace std;

int main()
{

	std::vector<Vector> v1 = {
		{1, 2},
		{3, 4},
		{4, 1},

	};

	Cov c(v1.begin(), v1.end());
	
	std::vector<Vector> cov = c.transform();
	
	for(std::size_t i=0; (i < cov.size()); i++)
	{
	   for(std::size_t j=0; (j < cov[i].size()); j++)
	   {
             std::cout << cov[i][j] << " "; 
	   }
	   std::cout << std::endl;
	}
	   
	return 0; 
}
