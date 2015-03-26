#include <iostream>
#include <vector>
#include <math.h>
#include "PCA.h"
#include <deque>
#include <cassert>
using namespace std;

PCA::PCA() {

}
std::ostream& operator <<(std::ostream&, PCA& a)
{
   std::cout << "(";
   for(std::size_t i=0; (i < a.cov_matrix.size()); i++)
   {
	for(std::size_t j=0; (j < a.cov_matrix[i].size()); j++)
	{
	    std::cout << a.cov_matrix[i][j] << ", ";
	}
	std::cout << std::endl;
   }
   std::cout << ")";

   std::cout << std::endl;
}
std::vector<Vector> PCA::getEigen()
{
   return this->values;
}

/*
void PCA::Solve() {
    //this->cov_matrix = cov();

   //this->values = Eigen::solveEigen(this->cov());


}
*/
std::vector<Vector> PCA::cov() {

   return c.transform();
}
