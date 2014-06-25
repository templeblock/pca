#include <iostream>
#include <vector> 
#include <algorithm>
#include <math.h>
#include <iomanip>
#include "../src/Cov.h"
#include "../src/Eigen.cpp"
double meanCol(std::vector<std::vector<double> > data, const std::size_t columnIndex)
{
    double mean = 0; 
    for(std::size_t i=0; (i < data.size()); i++)
    {
	mean += data[i][columnIndex]; 
    }

    return mean/data.size();
}

std::vector<std::vector<double> >  subtractMean(std::vector<std::vector<double> > &data)
{
    std::vector<std::vector<double> > vals(data.size()); 
    for(std::size_t i=0; (i < data.size()); i++)
    {
	vals[i].resize(data[i].size());
	for(unsigned j=0; (j < data[i].size()); j++)
	{
	    //std::cout << data[i][j] << "-" << meanCol(data, j) << " = " <<
	    double x =  (data[i][j] - meanCol(data, j));// << " ";
	    //data[i][j] = x;
	    vals[i][j] = x;   
	}
	//std::cout << std::endl;
    }
    return vals;
}

int main()
{
    
   std::vector<std::vector<double> > data = {
	{1, 2}, 
	{10, 3},
   	{1, 0}
   }; 

   auto data2 = subtractMean(data);

   Cov c(std::begin(data2), std::end(data2));

   auto cov_matrix = c.transform();
   
   // Get the Eigen values
   auto eigenValuesVectors = Eigen::solveEigen(cov_matrix);

   // Sort the Eigenvalues and Eigenvectors (descending)
   std::sort(eigenValuesVectors[0].begin(), eigenValuesVectors[0].end(), [](int a, int b) {
        return b < a;   
    }); 
	
   for(auto i : eigenValuesVectors[0])
   {
	std::cout << i << std::endl;
   }


	
    
   return 0;
}

