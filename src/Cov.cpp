#include <iostream>
#include <vector>
#include <cassert>
#include "Cov.h"

using namespace std;

Cov::Cov() {


}

void Cov::add_elements(Vector& lhs, const Vector& rhs) 
{
	assert(lhs.size() == rhs.size());
	for(std::size_t i = 0; (i < lhs.size()); i++)
	{
		lhs[i] += rhs[i]; 
	}
}
void Cov::sub_elements(Vector& lhs, const Vector& rhs)
{
	assert(lhs.size() == rhs.size());
	for(std::size_t i = 0; (i < lhs.size()); i++)
	{
		lhs[i] -= rhs[i];
	}
}
void Cov::scale(Vector& lhs, const double factor) {

	for(unsigned i=0; (i < lhs.size()); i++)
	{
		lhs[i] *= factor;
	}
}

Vector Cov::mean(const std::vector<Vector>& data)
{
	assert(data.size() > 0); 
	Vector result(data[0].size(), 0.0); 

	for(unsigned i=0; (i < data.size()); i++)
	{
		add_elements(result, data[i]); 
	}

	scale(result, 1.0 / data.size()); 
	return result;
}
std::vector<Vector> Cov::outer_product() {
	const std::size_t N = data[0].size(); 

	std::vector<Vector> outer(N, Vector(N, 0.0));

	for(std::size_t i = 0; (i < data.size()); i++) {
		for(std::size_t j=0; (j < N); j++)
		{
			outer[j][j] += data[i][j] * data[i][j];
			for(std::size_t k = j+1; (k < N); k++) {
				//std::cout << "Data.." << data[i][j] << "*" << data[i][k] << std::endl;
				double temp = data[i][j] * data[i][k];
				outer[j][k] += temp;
				outer[k][j] += temp;				
			}
		}
	}

	return outer;
} 
std::vector<Vector> Cov::transform() {

	assert(output.size() > 0);
	return this->output;

}
