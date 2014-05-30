#include <iostream>
#include <vector>
#include <deque>
#include <cassert>
#include <math.h>
#include "Eigen.h"
#include "Determinant.cpp"
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

}

std::vector<Vector> Eigen::solveEigen(std::vector<Vector> data)
{
    std::vector<Vector> eigen_values; 

    // Deduce the dimensions 
    auto dims = Helper::dimensions(data); 

    if(dims[0] == 2)
       eigen_values = Eigen::eig2(data);

    return eigen_values; 
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
    float lambda2 = -((eigen_values[0] - a)/b) / sqrt(lambda1);

    eigen_vectors.push_back(1 / sqrt(lambda1));
    eigen_vectors.push_back(lambda2); 
    
    eigen_properties.push_back(eigen_values);
    eigen_properties.push_back(eigen_vectors); 

    return eigen_properties;

}
