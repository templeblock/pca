#include <iostream>
#include <vector>
#include <math.h>
#include "PCA.h"
#include <deque> 
#include <cassert>
#include "Determinant.cpp"
using namespace std; 

namespace Helper {
	
   template<typename V>
   std::deque<std::size_t> dimensions(V const& vect)
   {
       return {}; 
   }
   
   template<typename T>
   std::deque<std::size_t> dimensions(std::vector<T> const& v)
   {
       if(v.empty())
        return {0};  
       else {
         auto dims = dimensions(v.front()); 
         dims.push_front(v.size()); 
         return dims;   
             
       }
   }
}

PCA::PCA() {

} 

Eigen PCA::eignvalues()
{
	return this->values;
}

void PCA::eig2() {


	// get the dimensions of the data

	std::vector<Vector> cov_matrix = this->cov(); 

    auto dim = Helper::dimensions(cov_matrix); 

    const std::size_t dim1 = dim[0];
    std::size_t dim2 = dim[1];
	// Store each of the linear values..

	float a = cov_matrix[0][0]; 
	float b = cov_matrix[1][0]; 
	float c = cov_matrix[1][1]; 

	float deter = 0.0; 

	if(dim[0] == 2)
	{
		deter = Determinant::determinant<2>(cov_matrix);  
	}else if(dim[0] == 3)
	{
		std::cout << "This is 3";

	}
	if(deter < 0)
	{
		deter = 0; 
	}

	values.lambda1 = (a+c+sqrt(deter))/2; 
	values.lambda2 = (a+c-sqrt(deter))/2;

	std::cout << std::endl << values.lambda1;
	std::cout << std::endl << values.lambda2;
	//float determinant = Determinant::determinant<dim[0], dim[1]>(cov_matrx);

	///float d = (a + c) * (a + c) - 4 *(a*c-b*b);
	/*if(d < 0)
	{
		d = 0; 
	}
		



	// Assign the Eign values 

	values.lambda1 = (a+c+sqrt(d))/2;
	values.lambda2 = (a+c-sqrt(d))/2;
 	
 	/*for(unsigned i=0; (i < cov_matrix.size()); i++)
	{
		for(unsigned j=0; (j < cov_matrix[i].size()); j++)
		{
			std::cout << cov_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}*/

}
std::vector<Vector> PCA::cov() {

	return c->transform();
} 
