#include <iostream>
#include <vector>
#include <algorithm> 
#include "../src/Determinant.cpp"

/* This examples shows how to use the PCA
   library to find the Determinant of a given
   matrix (vector). This example demonstrates
   the Determinant for a 2x2, 3x3 and 4x4 matrix.
*/

int main() 
{
   std::vector<std::vector<double> > data2  = {
	{1, 2},
	{4, 1},
   }; 

   std::cout << Determinant::determinant<2>(data2); 
   
   std::vector<std::vector<double> > data3 = {
	{4, 6, 10},
	{3, 10, 13},
	{-2, -6, -8}
   };
  
   std::cout << Determinant::determinant<3>(data3);
   
   std::vector<std::vector<double> > data4 = {
       {4, 3, 1, 1},
       {1, 2, 1, 2},
       {2, 1, 1, 1},
       {1, 2, 1, 1}
   }; 
   
   std::cout << Determinant::determinant<4>(data4);



   return 0;
}
