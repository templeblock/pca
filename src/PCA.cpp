#include <iostream>
#include <vector>
#include <math.h>
#include "PCA.h"
#include <deque> 
#include <cassert>
using namespace std; 

PCA::PCA() {

} 

std::vector<Vector> PCA::getEigen()
{
   return values;
}

void PCA::Solve() {

    values = Eigen::solveEigen(this->cov());

}

//void PCA::eig2() {

    // get the dimensions of the data

   /* std::vector<Vector> cov_matrix = this->cov(); 

    auto dim = Helper::dimensions(cov_matrix); 

    const std::size_t dim1 = dim[0];
    const std::size_t dim2 = dim[1];
    // Store each of the linear values..
   
    float a = cov_matrix[0][0]; 
    float b = cov_matrix[1][0]; 
    float c = cov_matrix[1][1];

     float deter = 0.0; 

     if(dim[0] == 2)
     {
	  deter = Determinant::determinant<2>(cov_matrix);  
    	  for(std::size_t i=0; (i < cov_matrix.size()); i++)
          {
	     for(std::size_t j=0; (j < cov_matrix[i].size()); j++)
             {
		 std::cout << cov_matrix[i][j] << " ";
			
             }
	     std::cout << std::endl;

	  } 	
	
     }else if(dim[0] == 3)
     {	
	deter = Determinant::determinant<3>(cov_matrix);
	// std::cout << "This is 3";
     }
     if(deter < 0)
     {
	 deter = 0; 
     }

     values.lambda1 = (a+c+sqrt(deter))/2; 
     values.lambda2 = (a+c-sqrt(deter))/2;
 	
     float aa = (1 * 1) + (values.lambda1 - a)/b * (values.lambda1 - a)/b;
   
     //float aa = 1*1 + (9.00 - 4.5) * (9.00 - 4.5) / 4.5; 
     // float aa = (9.0 - 4.5) * (9.0 - 4.5))/3 + (1 * 1); 
	    
     float aaa =  1 / sqrt(aa); 
     float bbb =  ((values.lambda1 - a)/b) / sqrt(aa); 
     std::cout << "L 1: " <<  aaa << std::endl;
     std::cout << "L 2: " << bbb << std::endl;	
     // std::cout << values.lambda1 << std::endl;
     // std::cout << a << std::endl << b << std::endl << c << std::endl;  
     // std::cout << values.lambda1 << std::endl;
    
    // std::cout << "VECTOR: " <<  1 * (values.lambda1 - a) / 3;
    */ 
//}
std::vector<Vector> PCA::cov() {

	return c.transform();
} 
