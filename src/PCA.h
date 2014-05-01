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
			c = new Cov(begin, end); 
			eig2();
		}

		std::vector<Vector> cov(); 

		void eig2();

		void pca_helper(); 	

		Eigen eignvalues();

	

	private:
		Cov* c; 
		std::vector<Vector> data; 
		Eigen values;

}; 
