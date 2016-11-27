#include "Enumeration.h"
#include"Image.h"
#include <cmath>

using namespace std;

std::pair<int, int> Enumeration(Image* image, const int& image_size) {
    pair<int, int> shortest;
    double short_dis = -1;
    for (int i = 0; i < image_size; i++) {
        int* data1 = image[i].Get_Arr();
        int size1 = image[i].Get_Size();
        double distance;

        for (int j = i + 1; j < image_size; j++) {
            int* data2 = image[j].Get_Arr();
            int size2 = image[j].Get_Size();
            double ij_dis = 0;

            for (int k = 0; k < size1; k++) {
                ij_dis += pow(data1[k] - data2[k], 2);
            }
            distance = (double)sqrt(ij_dis);
            if (short_dis == -1) {
                short_dis = distance;
                shortest = make_pair(i, j);
            }
            else if (distance < short_dis) {
                short_dis = distance;
                shortest = make_pair(i, j);
            }
        }
    }
    return shortest;
}
