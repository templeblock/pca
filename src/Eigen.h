#include <iostream>
#include <vector>
typedef std::vector<double> Vector;

namespace Eigen {

	std::vector<Vector> solveEigen(std::vector<Vector> data); 
	std::vector<Vector> eig2(std::vector<Vector> data);
	std::vector<Vector> eig3(std::vector<Vector> data);
}
