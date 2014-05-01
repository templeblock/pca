#include <iostream>
#include <vector> 
typedef std::vector<double> Vector;
using namespace std;

namespace Determinant {

	template<int X>
	float determinant(std::vector<Vector> &data)
	{	
		// Determine if X and Y are 3
		float deter = 0.0;
		if(X == 2)
		{
			float a = data[0][0]; 
			float b = data[1][0]; 
			float c = data[1][1]; 
			
			deter = (a + c) * (a + c) - 4 *(a*c-b*b);

		}else if(X == 3)
		{
			std::cout << "Looks 3-dimensional!!";
		}
		return deter; 
	}

}