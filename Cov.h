#include <iostream>
#include <vector>

typedef std::vector<double> Vector; 

class Cov {

	public:

		Cov(); 

		template<typename T> 
		Cov(T begin, T end)
			: data(begin, end) 
		{
			std::vector<Vector> data_temp = data; 

			Vector mean_product = mean(data); 
			
			for(auto& vect : data)
			    sub_elements(vect, mean_product); 
			
			// Multiplies the outer product
			this->output = outer_product();
		}



		std::vector<Vector> transform(); 
		
		void add_elements(Vector& lhs, const Vector& rhs);
		void sub_elements(Vector& lhs, const Vector& rhs); 
		void scale(Vector& lhs, const double scale);
		
		Vector mean(const std::vector<Vector>& data); 
		std::vector<Vector> outer_product(); 
		//std::vector<Vector> outer_product(const std::vector<Vector> data);

	protected:	

		std::vector<Vector> data; 
		std::vector<Vector> output;
};