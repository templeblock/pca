#include <iostream>
#include <vector>
#include <deque>
#include <cassert>
#include <math.h>
#include "Eigen.h"
#include "Determinant.cpp"
#include "Helper.h"

typedef std::vector<double> Vector;

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
	       dims.push_back(v.size());
	       return dims; 
	     }
     }
	
     /* The following methods do not relate to Eigenvalues, as such
	      but are infact helper functions to allow for the Polynomial 
	      equation to be solved. Feel free to remove these functions
	      and place them in a more appropriate file 
     */ 

      float trace(std::vector<Vector> data) {
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
              for(std::size_t j=0; (j < matrix1[0].size()); j++)
              {
                  for(std::size_t k=0; (k < matrix1[0].size()); k++)
                      temp[i][j] = temp[i][j] + (matrix1[i][k] * matrix2[k][j]); 
              }
          }
          return temp;
        }

      std::vector<double> polysolver(std::vector<Vector> data)
      {
	   /* Will do more error checking*/ 

	   std::vector<double> characteristics(4, 0); 
	   
	   // Calculate the first characteristic 
	   characteristics[0] = 1; 
	   // Calculate the characteristic for the trace 
	   characteristics[1] = -(trace(data)); 
	   // Calculate the 3rd characteristic
	   characteristics[2] = trace(data)*trace(data) - trace(multiply_matrix(data, data)); 
	   characteristics[2] /= 2; 
	   characteristics[3] = Determinant::determinant<3>(data);
      	   
	   return characteristics; 
      }
}

std::vector<Vector> Eigen::solveEigen(std::vector<Vector> data)
{
    std::vector<Vector> eigen_values; 

    // Deduce the dimensions 
    auto dims = Helper::dimensions(data); 

    if(dims[0] == 2)
       eigen_values = Eigen::eig2(data);
    
    if(dims[0] == 3)
       eigen_values = Eigen::eig3(data); 

    if(dims[0] == 4)
      //eigen_values = Eigen::eig4(data); 

    //eigen_values = Eigen::eig2(data); 
   		    
    //std::cout << eigen_values.size(); 	
    //std::cout << dims[0] << std::endl << dims[1] << std::endl;
    
    return eigen_values; 
}


std::vector<Vector> Eigen::eig3(std::vector<Vector> data){
  
   std::vector<Vector> eigen_properties; 
    
   /*
      This method calculates the Eigenvalues of a 3x3 matrix
      In the first instance, we will calculate the characteristic
      polynomial and using the quad eq, find the roots of the cublic 
      results.
   */ 
   auto poly_characteristics = Helper::polysolver(data);     
   
   // Calculate the Eigen values, there will be 3
   Vector eigen_values;
   // Shorten the calulations, we will use this instance
   // for both of the quad equations:
   float cal1 = fabs(poly_characteristics[1] * poly_characteristics[1]);
   float cal2 = 4 * (poly_characteristics[0] * poly_characteristics[2]);

   eigen_values.push_back((fabs(poly_characteristics[1]) + sqrt(cal1 - cal2)) / 2);
   eigen_values.push_back((fabs(poly_characteristics[1]) - sqrt(cal1 - cal2)) / 2);


   return eigen_properties; 
}

std::vector<Vector> Eigen::eig2(std::vector<Vector> data) {

    std::vector<Vector> eigen_properties; 

    float a = data[0][0]; 
    float b = data[1][0];
    float c = data[1][1];

    float determinant = 0.0; 

    determinant = Determinant::determinant<2>(data);
    if(determinant < 0.0)
       determinant = 0.0; 

    Vector eigen_values; 

    eigen_values.push_back( (a+c+sqrt(determinant))/2 );
    eigen_values.push_back( (a+c-sqrt(determinant))/2 ); 
    
    // calculate the Eigen vectors 
    Vector eigen_vectors; 

    float lambda1 = (1*1) + (eigen_values[0] - a)/b * (eigen_values[0] - a)/b;
    float lambda2 = ((eigen_values[0] - a)/b) / sqrt(lambda1);

    eigen_vectors.push_back(1 / sqrt(lambda1));
    eigen_vectors.push_back(-lambda2); 
    
    eigen_properties.push_back(eigen_values);
    eigen_properties.push_back(eigen_vectors); 

    return eigen_properties;

}
