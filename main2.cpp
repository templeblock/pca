#include <iostream>
#include <vector>

using namespace std; 

typedef std::vector<std::vector<double> > Matrix;

double meanColumnOrder(const Matrix& matrix,const int columnIndex)
{
	double mean = 0.0; 
	for(unsigned i = 0; i < matrix.size(); ++i){
		mean += matrix[i][columnIndex];
	}
	return (mean) / matrix.size();
}
 
void subtractMeanOrder(Matrix& matrix, const int columnIndex, double mean)
{
	for(unsigned i=0; (i < matrix.size()); i++){
		/*std::cout << matrix[i][columnIndex] << "- " << mean << " = "
		<< matrix[i][columnIndex] - mean << std::endl;*/
 
		double value = matrix[i][columnIndex] - mean;
		matrix[i][columnIndex] = value;
	}
 
}

void multiple(Matrix& matrix, const int columnIndex)
{
	for(unsigned i=0; (i < matrix.size()); i++)
	{
		double val  = matrix[i][columnIndex]  * matrix[i][columnIndex];// << std::endl;
		
		matrix[i][columnIndex] = val;
	}
}

void add(Matrix& matrix, const int columnIndex)
{
	for(unsigned i=0; (i < matrix.size()); i++)
	{
			double val = matrix[i][columnIndex] + matrix[i][columnIndex];

			matrix[i][columnIndex] = val;
	}

}

void scale(Matrix& matrix, double alpha)
{
	for(unsigned i=0; (i < matrix.size()); i++)
	{
		for(unsigned j=0; (j < matrix[i].size()); j++)
		{
			double val = matrix[i][j] *= alpha; 
			matrix[i][j] = val;

		}
	}

}
int main() {
	// your code goes here
	std::vector<std::vector<double> > v1 = { {1, 2}, 
											 {3, 3}, 
										   };
 
    // Calculate the means 
	std::vector<float> means; 
 
	for(unsigned i=0; (i < v1.size()); i++)
	{
		means.push_back(meanColumnOrder(v1,i));// << std::endl;
	}
 
	// Subtract all the values from the mean
 
	for(unsigned i=0; (i < v1.size()); i++)
	{
		subtractMeanOrder(v1, i, means[i]);
 
	}
	Matrix m(v1.size()); 

	for(unsigned i=0; (i < v1.size()); i++)
	{
		m[i]	
 
	}
	for(unsigned i=0; (i < v1.size()); i++)
	{
		add(v1, i);
 
	}

	scale(v1, 1/(2 - 1));

	for(unsigned i=0; (i < v1.size()); i++)
	{
		for(unsigned j=0; (j < v1[i].size()); j++)
		{
			std::cout << v1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	/*
		matrix looks like this:
		
		2.5, 2.4
		0.5, 0.7
		
		mean[0] = (2.5 + 0.5)/2
		mean[1] = (2.4 + 0.7)/2
	*/
	
	return 0;
}
