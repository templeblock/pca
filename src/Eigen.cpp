#include <iostream>
#include <vector>

#include <deque>
#include <cassert>

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
	   dims.push_front(v.size());
	   return dims;   
	 }
     }
}

namespace Eigen {

   template<typename T>   
   std::vector<Vector> solveEigen(T begin, T end)
   {
	/*
	     This method solves the Eigen values and vectors 
	     for square matrices. The method deduces the 
	     dimensionality 
       */ 
       std::vector<Vector> eigen_values; 

       // deduce the dimensionality 
       std::vector<Vector> cov_matrix(begin, end); 
       
       auto dims = Helper::dimensions(cov_matrix); 

       std::cout << dims[0];

       return eigen_values; 

   }


}
