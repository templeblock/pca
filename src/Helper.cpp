#include <iostream>
#include <vector> 
#include "Helper.h"

float Helper::trace(std::vector<Vector> data) {
    
    if(data.size() == 0)
      exit(0); 

    float trace = 0.0; 
    
    for(std::size_t i=0; (i < data.size()); i++)
    {
 	for(std::size_t j=0; (j < data[i].size()); j++)
	{
	    if(i == j)
	    {	
		trace += data[i][j]; 
	    }
	}
    }
   
    return trace; 
}
std::vector<Vector> multiply_matrix(std::vector<Vector> matrix1,
		std::vector<Vector> matrix2)
{
	std::vector<Vector> temp; 
	temp.resize(matrix1.size()); 
	for(std::size_t i=0; (i < matrix1.size()); i++)
	{
	    temp[i].resize(matrix1[i].size());
	    for(std::size_t j=0; (j < matrix[0].size()); j++)
	    {
		temp[i][j] = temp[i][j] + (matrix1[i][k] * matrix2[k][j]); 

 	    }
	}
	return temp;
}
