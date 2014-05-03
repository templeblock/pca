#include <iostream>
#include <vector>
#include "../src/PCA.h"


int main()
{

	std::vector<std::vector<double> > data_2 = { 
		{-2, -1}, {1,2},

	};

	PCA pca(std::begin(data_2), std::end(data_2));
	std::cout << pca << std::endl;
	return 0;

}
