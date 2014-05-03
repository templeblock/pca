#include <iostream>
#include <vector>
#include "Cov.h"

typedef std::vector<double> Vector; 

struct Eigen {
	float lambda1;
	float lambda2; 
};
class PCA {

	public: 

	   PCA(); 

	   template<typename T>
	   PCA(T begin, T end) 
	   : data(begin, end)
	   {
		c = Cov(begin, end); 
		
	   }

	   std::vector<Vector> cov(); 
		
	   std::vector<Vector> getEigen(); 

	   void solveEigen(); 
		
	private:
	  Cov c; 
	  std::vector<Vector> data; 
	  std::vector<Vector> values; 

}; 
