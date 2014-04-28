#include <iostream>
#include <vector>
#include "../PCA.h"


int main()
{

	std::vector<std::vector<double> > data = { {-2, -1}, {1, 2} };

	PCA pca(std::begin(data), std::end(data));

	return 0;

}