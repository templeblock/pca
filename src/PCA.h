#include <iostream>
#include <vector>
#include "Cov.h"
#include "Eigen.h"
typedef std::vector<double> Vector;


class PCA {

	public:

	   PCA();

	   template<typename T>
	   PCA(T begin, T end)
	   : data(begin, end)
	   {
				c = Cov(begin, end);

				Solve();
	   }

	   std::vector<Vector> cov();

	   std::vector<Vector> getEigen();


	   void Solve();

	   	friend std::ostream& operator <<(std::ostream&, PCA& a);
	private:
	  Cov c;
	  std::vector<Vector> cov_matrix;
	  std::vector<Vector> data;
	  std::vector<Vector> values;

};
