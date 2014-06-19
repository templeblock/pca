## Principle Component Analaysis
===
### About
Whilst undertaking a research project, a large dataset was used and PCA analysis had to be carried out
in order to reduce the dimensionality, as well as provide a feature based training system for one of 
the predictive models that was developed. There were many existing software packages centered around this,
and, all of which provided a reasonable amount of functionality. One of the main issues that the software
packages were very complicated, both to install and access the core features - Sometimes now even allowing
for the internal features to be used. There were also little examples which made it fustrating. 

I developed this PCA library to be small and compact and tried to keep the funcionality to an absolute minimum. 
The great advantage of this library is that developing this meant that we could implement some of the core features
and techniques in Linear Algebra, and, because of this these functions were opened up - So it doesn't mean that you
have to use the library for just PCA but also this library can be used for carrying out small calculations your data.

The main concepts were implemented following this paper: http://www.math.union.edu/~jaureguj/PCA.pdf and if you're not familar with the concept of PCA then you should check the paper out. 

### Your Data
In order to maintain the easiability to carrying out PCA on data, it was important to develop a method that automatically
detects what the dimesionality and with this, we presented a method based on the Factory design pattern. This works so that,
you can enter any dimensionality of data (e.g. 2x2 3x3) and the software library will choose the most appropriate 
function to calculate the Eigenvalues and Eigenvectors. For example:

```
   std::vector<std::vector<double> data = {
        {1, 2}.
        {3, 4},
        {5, 6}
   }
```



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
```

