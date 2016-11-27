#include<utility>
#include<cmath>
#include<iostream>
#include<string>
#include"Image.h"
#include"algorithm4.h"
#include"algorithm3.h"
#include"algorithm2.h"
#include"algorithm1.h"

const double max_number = 999999999999;

double Euclidean_Distance(const int &a, const int &b, Image* image){
    double distance = 0;
    int* p = image[a].Get_Arr();
    int* q = image[b].Get_Arr();
    int size = image[a].Get_Size();
    for (int i = 0; i < size; ++i) {
        distance = sqrt((p[i]-q[i])*(p[i]-q[i]));
    }
    return distance;
}


std::pair<int, int> Closet_Pair1(const int& n, Image* image, const int& m) {
    std::pair<int, double>** S;
    S = Random_Projection(n, image, m);
    std::pair<int, int> cp;
    double min = max_number;
    for (int i = 0; i < m; ++i) {
        std::pair<double, std::pair<int, int> >temp = Closet_Pair_M(S[i], n);
        double dist = Euclidean_Distance(temp.second.first, temp.second.second, image);
        if (min > dist) {
            min = dist;
            cp = std::make_pair(temp.second.first, temp.second.second);
        }
    }
    for (int i = 0; i < m; ++i) {
      delete[]S[i];
    }
    delete[]S;
    return cp;
}

std::pair<int, int> Closet_Pair2(const int& n, Image* image, const int& m) {
    std::pair<int, double>** S;
    S = Random_Projection(n, image, m);
    std::pair<int, int> cp;
    double min = max_number;
    for (int i = 0; i < m; ++i) {
        double* temp = Closet_Pair_Q(S[i], n);
        double dist = Euclidean_Distance(temp[1], temp[2], image);
        if (min > dist) {
            min = dist;
            cp = std::make_pair(temp[1], temp[2]);
        }
        delete []temp;
    }
    for (int i = 0; i < m; ++i) {
      delete[]S[i];
    }
    delete[]S;
    return cp;
}
