## PCA
===

Implementation for the Principle Component Analysis, which, implemented using the proposed approach given in: (http://www.math.union.edu/~jaureguj/PCA.pdf)

### Installing Compiling examples 
===

#### To install (Linux)
```bash
git clone https://github.com/Phorce/pca.git

cd ~/Dir/pca 
Make
```
#### Running the examples 
Included is some working examples, these have been tested on both Linux as well as the Mac operating system.
Please note, C++11 is required in order to run the examples. These invoke standard ```std::vector``` as a given. 

``` 
g++ example/PCA.cpp -std=c++11 PCA.so
g++ examplees/Cov.cpp -std=c++11 PCA.so
````
