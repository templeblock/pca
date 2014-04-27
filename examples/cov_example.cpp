#include <iostream>
#include <vector>
#include "src/Cov.h"

using namespace std;

int main()
{

	std::vector< Vector > v1 = { {1, 2}, {3, 3}, {2, 4}, {0.4, -2} };

	Cov c(v1.begin(), v1.end());

	return 0; 
}