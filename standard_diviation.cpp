#include <iostream>
#include <vector>

using namespace std;

double meanCol(std::vector<std::vector<double> > data, const std::size_t columnIndex)
{
     double mean = 0; 
     for(std::size_t i=0; (i < data.size()); i++)
     {	
	 mean += data[i][columnIndex]; 
     }
     mean /= data.size();
     return mean; 
}
std::vector<std::vector<double> > subtractMean(std::vector<std::vector<double> > data)
{
    double x = 0.0;  
    std::vector<std::vector<double> > y; 
    y.resize(data.size());
    for(unsigned i=0; (i < data.size()); i++)
    {
	 y[i].resize(data[i].size());
	 for(unsigned j=0; (j < data[i].size()); j++)
	 {
 	     double x = meanCol(data, j);
	    // std::cout << (data[i][j] -  x) << " ";
	     double xa = (data[i][j] - x); 
	     y[i][j] = xa * xa; //(data[i][j] - x * data[i][j] - x); 
	 }
    }
    return y;
}

std::vector<double> sd(std::vector<std::vector<double> > data)
{
    std::vector<double> standard; 
    
    auto subtracted = subtractMean(data);
    for(unsigned i=0; (i < subtracted.size()); i++)
    {
        for(unsigned j=0; (j < subtracted[i].size()); j++)
	{
	   std::cout << subtracted[i][j] << " ";
	}
	std::cout << std::endl;
    }
    return standard;

}


int main()
{
   
   std::vector<std::vector<double> > data = {
	{4, 1},
	{1, 2},


   };
  
  std::vector<double> stand = sd(data);

   return 0;
}
