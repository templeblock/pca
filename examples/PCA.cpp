#include <iostream>
#include <vector>
#include "../PCA.h"


int main()
{

	std::vector<std::vector<double> > data = { {-2, -1}, {0, 1},
							 				   {2, 2}, {4, 5}, 
							 				   {6, 7}, {8, 9}, 
							 				   {10, 11}, {12, 13},
							 				   {14, 15}, {16, 17},
							 				   {18, 19}, {20, 21}};

	PCA pca(std::begin(data), std::end(data));

	// Generate a random 2x2 matrix 

	auto testData = pca.generate(100, 2); 

	for(unsigned i=0; (i < testData.size()); i++)
	{
		for(unsigned j=0; (j < testData[i].size()); j++)
		{
			std::cout << testData[i][j] << " ";
		}
		std::cout << std::endl;
	}
	/* 
		return and print the Eingen 
	
	*/
	/*auto values = pca.eignvalues();
	std::cout << values.lambda1 << std::endl;
	std::cout << values.lambda2;
	*/
	return 0;

}