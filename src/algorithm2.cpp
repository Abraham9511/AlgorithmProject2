#include<iostream>
#include<cassert>
#include<cmath>
#include<random>
#include<ctime>
#include<cstdlib>
#include"Image.h"
#include"algorithm2.h"

using std::cin;
using std::cout;
using std::endl;

template <class T>
void boxmuller(T* data, size_t count){
    assert(count % 2 == 0);
    static const T twopi = T(2.0 * 3.14159265358979323846);
    //std::default_random_engine generator;
    //std::uniform_int_distribution<T> distribution(0.0,1.0);
    srand((unsigned)time(NULL));
    for (size_t i = 0; i < count; i += 2) {
        T u1 = 1.0f - rand()/((double)(RAND_MAX)); // [0, 1) -> (0, 1]
        T u2 = rand()/((double)(RAND_MAX));
        T radius = std::sqrt(-2 * std::log(u1));
        T theta = twopi * u2;
        data[i] = radius * std::cos(theta);
        data[i+1] = radius * std::sin(theta);
    }
}

std::pair<int,double>** Random_Projection(const int& n, Image* image, const int& m) {
    double **a = new double*[m];
    std::pair<int, double>** S = new std::pair<int, double>*[m];
    for (int i = 0; i < m; ++i) {
        a[i] = new double[m];
        S[i] = new std::pair<int, double>[n];
    }

    for (int i = 0; i < m; ++i) {
        boxmuller<double>(a[i], m);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            S[j][i].first = i;
            S[j][i].second = image[i].Multiply(a[j]);
        }
    }

    for (int i = 0; i < m; ++i) {
      delete[] a[i];
    }
    delete[]a;
    
    return S;
}
