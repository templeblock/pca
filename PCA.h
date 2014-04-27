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
			 this->pca_helper(); 
		}

		void pca_helper(); 	

	private:
		Cov* c; 
		std::vector<Vector> cov_matrix; 
		std::vector<Vector> data; 


}; 