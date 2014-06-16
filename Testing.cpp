#include <iostream>
#include <vector> 
//#include "src/PCA.h"
#include "src/Determinant.cpp"
#include "src/Cov.h"

using namespace std;

float trace(std::vector<std::vector<double> > data)
{
    // Compute the trace, take the summation 
   // of the diag lines 
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

// This method multiples Matrix A by Matrix B
std::vector<std::vector<double> > multiply_matrix(std::vector<std::vector<double> > data, 
						  std::vector<std::vector<double> > data2)
{  
	std::vector<std::vector<double> > temp; 
        temp.resize(3); 
	for(std::size_t i=0; (i < data[0].size()); i++)
	{
	    temp[i].resize(data[0].size());
	    for(std::size_t j=0; (j < data[0].size()); j++)
	    {
		for(std::size_t k=0; (k < data[0].size()); k++)
		   temp[i][j] = temp[i][j] + (data[i][k] * data2[k][j]);
	    }
	}
	return temp;
}

// Method for calculating the Polynominal 
// Initial implementation, may need work and testing.
// Implements the following equation (with proof)

std::vector<double> polysolver(std::vector<std::vector<double> >  data)
{
    std::vector<double> characteristics(4, 0); 
    // Calculate the first polynomial 
    // The first characteristic will be "1" 
    characteristics[0] = 1; 
    // Calculate the second characteristic polynomial 
    characteristics[1] = -(trace(data)); 
    // Calculate the 3rd characteristic:
    // Firstly, store the trace
    characteristics[2] = trace(data)*trace(data) - trace(multiply_matrix(data, data));
    characteristics[2] /= 2; 
    // The final characteristic
    characteristics[3] = Determinant::determinant<3>(data);

    return characteristics; 

}

int main() {
  
  std::vector<std::vector<double> > vals = {

	{4, 6, 10},
	{3, 10, 13},
	{2, 6, 8}
  }; 
  auto characteristics = polysolver(vals);
  
  std::cout << characteristics[2];
  
  return 0; 
}
