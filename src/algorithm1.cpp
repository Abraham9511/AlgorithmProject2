#include"Image.h"
#include"algorithm4.h"
//#include"algorithm3.h"
#include"algorithm2.h"
#include"algorithm1.h"
#include<utility>
#include<cmath>

const double max = 999999999999;
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

std::pair<int, int> Closet_Pair(const int& n, Image* image, const int& m) {
    std::pair<int, double>** S;
    S = Random_Projection(n, image, m);
    std::pair<int, int> cp;
    double min = max;
    for (int i = 0; i < m; ++i) {
        int* temp = Closet_Pair_Q(S[i], n);
        double dist = Euclidean_Distance(temp[1], temp[2], image);
        if (min > dist) {
            min = dist;
            cp = std::make_pair(temp[1], temp[2]);
        }
    }
}
