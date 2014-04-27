#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector<double> Vector;
typedef std::vector< std::vector<double> > Matrix;

void add_assign(Vector& lhs, const Vector& rhs) {
  assert(lhs.size() == rhs.size());
  for(std::size_t i = 0; i < lhs.size(); ++i)
    lhs[i] += rhs[i];
}

void sub_assign(Vector& lhs, const Vector& rhs) {
  assert(lhs.size() == rhs.size());
  for(std::size_t i = 0; i < lhs.size(); ++i)
    lhs[i] -= rhs[i];
}

void scale_vector(Vector& lhs, double factor) {
  for(std::size_t i = 0; i < lhs.size(); ++i)
    lhs[i] *= factor;
}

Vector mean_vector(const std::vector<Vector>& data) {
  assert(data.size() > 0);
  Vector result(data[0].size(), 0.0);
  for(std::size_t i = 0; i < data.size(); ++i)
    add_assign(result, data[i]);
  scale_vector(result, 1.0 / data.size());
  return result;
}

void print_matrix(const Matrix& m) {
  for(auto& v : m) {
    std::cout << "(";
    for(auto x : v)
      std::cout << " " << x;
    std::cout << ")\n";
  }
}

int main() {
  // your code goes here
  std::vector< Vector > v1 = { {1, 2}, {3, 4} };
  
  std::cout << "v1 is\n";
  print_matrix(v1);
  
  // Calculate the means 
  Vector mean = mean_vector(v1);
  
  // Subtract the mean from all the vectors
  for(auto& v : v1)
    sub_assign(v, mean);
  
  std::cout << "v1 - mean is\n";
  print_matrix(v1);
  
  // calculate the scatter matrix:
  const std::size_t N = v1[0].size();
  Matrix pca_m(N, Vector(N, 0.0));
  for(std::size_t i = 0; i < v1.size(); ++i) {
    for(std::size_t j = 0; j < N; ++j) {
      pca_m[j][j] += v1[i][j] * v1[i][j];
      for(std::size_t k = j+1; k < N; ++k) {
        double tmp = v1[i][j] * v1[i][k];
        pca_m[j][k] += tmp;
        pca_m[k][j] += tmp;
      }
    }
  }
  
  std::cout << "pca_m is\n";
  print_matrix(pca_m);
  
  return 0;
}

