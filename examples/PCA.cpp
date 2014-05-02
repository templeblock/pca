#include <iostream>
#include <vector>
#include "../src/PCA.h"


int main()
{

	std::vector<std::vector<double> > data_2 = { {1, 2}, {3, 4}, {5, -1}, {1, 4}};

	PCA pca(std::begin(data_2), std::end(data_2));
	
	auto values = pca.eignvalues();
	
	//std::cout << values.lambda1 << std::endl << values.lambda2 << std::endl;
	

	/*std::vector<std::vector<double> > data_3 = { {10, 11, 22}, {1, 3, 18} }; 
	
	PCA pca2(std::begin(data_3), std::end(data_3));
	
	auto values2 = pca2.eignvalues(); 
	*/


	return 0;

}
