#include <iostream>
#include <vector>
#include <algorithm>
#include "../src/Eigen.h"

int main()
{
   /* Finding the Eigenvalues of a 3x3 matrix,
      without computing the Coveriance matrix
      HAS TO BE SQUARE
   */
   // In this example, the eigen values/vectors 
   // are for a 3x3 matrix. Computing other matrix
   // is as simple as just passing in the desired 
   // matrix format. 

   std::vector<std::vector<double> > data1 = {
       {4, 6, 10},
       {3, 10, 13},
       {-2, -6, -8}
   };
   //Eigen::eig3
   std::vector<std::vector<double> > eigen  = Eigen::eig3(data1); 
   
   std::for_each(std::begin(eigen), 
		 std::end(eigen), 
		 [&](std::vector<double> &data)
   {
	for(auto i : data)
	{
	    std::cout << i << " ";
	}
	std::cout << std::endl;
   });









}


