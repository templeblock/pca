#include <iostream>
#include <vector>
#include "src/PCA.h"


int main()
{

	std::vector<std::vector<double> > data = { {1, 2}, {3, 4} };

	PCA pca(std::begin(data), std::end(data));

	return 0;

}