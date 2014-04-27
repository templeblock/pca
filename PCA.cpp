#include <iostream>
#include <vector>
#include "PCA.h"

using namespace std; 

PCA::PCA() {

} 

void PCA::pca_helper() {

	c = new Cov(std::begin(data), std::end(data)); 

	cov_matrix = c->transform();

	/*	
		This function is not complete:
			1) Make it more efficient
			2) Add eig-vals 
			3) Add eig-vectors 
			
	*/	
}