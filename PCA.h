#include <iostream>
#include <vector>
#include "Cov.h"

typedef std::vector<double> Vector; 

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

	private:
		Cov* c; 
		std::vector<Vector> data; 

		struct Eigen {
			float lamda1;
			float lamda2; 
		};

}; 