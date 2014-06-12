#include <iostream>
#include <vector> 
typedef std::vector<double> Vector;
using namespace std;

namespace Determinant {
	
	
	template<int X>
	float determinant(std::vector<Vector> &data)
	{	
	
		float deter = 0.0;
		if(X == 2)
		{
			float a = data[0][0]; 
			float b = data[1][0]; 
			float c = data[1][1]; 
						
		
			deter = (a + c) * (a + c) -4 * (a*c-b*b);
		}else if(X == 3)
		{	
		    /* Slightly hard-coded, but best option 
		       around ASAIK, there maybe alternations 
		       to this but this is for a standard
		       3x3 matrix*/
		    
		    float determinant1 = (data[1][1] * data[2][2]) - (data[2][1] * data[1][2]); 
		    float determinant2 = (data[1][0] * data[2][2]) - (data[2][0] * data[1][2]); 
		    float determinant3 = (data[1][0] * data[2][1]) - (data[2][0] * data[1][1]);

		    deter = (data[0][0] * determinant1) - (data[0][1] * determinant2) + (data[0][2] * determinant3);

		    //std::cout << deter << std::endl;	   
			  
		}
		return deter; 
	}

}
