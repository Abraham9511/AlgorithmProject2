#include "Enumeration.h"
#include "Image.h"
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

std::vector<std::pair<int, int> > Enumeration(Image* image, const int& image_size) {
    vector<pair<int, int> > p;
    pair<int, int> temp;
    vector<double> dis;

    pair<int, int> shortest;
    //取第i个点
    for (int i = 0; i < image_size; i++) {
        int* data1 = image[i].Get_Arr();
        int size1 = image[i].Get_Size();
        double distance;
        double short_dis = -1;
        //将第i个点与后面的点逐一比较
        for (int j = i + 1; j < image_size; j++) {
            int* data2 = image[j].Get_Arr();
            int size2 = image[j].Get_Size();
            double ij_dis = 0;
            //计算每个维度
            for (int k = 0; k < size1; k++) {
                ij_dis += pow(data1[k] - data2[k], 2);
            }
            distance = (double)sqrt(ij_dis);
            /*if (short_dis == -1) {
                short_dis = distance;
                shortest = make_pair(i, j);
            }
            else if (distance < short_dis) {
                short_dis = distance;
                shortest = make_pair(i, j);
            }*/

            //当前的两点
            temp = make_pair(i, j);
            //第一次计算vector为空,简单推入
            if (p.size() == 0) {
                p.push_back(temp);
                dis.push_back(distance);
            } else {
            //通过比较距离计算出pair在vector应该处于的位置
                int pos;
                for (pos = 0; pos < dis.size(); pos++) {
                    if (dis[pos] > distance) {
                        break;
                    }
                }
                dis.insert(dis.begin() + pos, distance);
                p.insert(p.begin() + pos, temp);
                //保证vector的大小不超过BACK常量
                while (p.size() > BACK) {
                    p.erase(p.end() - 1);
                    dis.erase(dis.end() - 1);
                }
            }
        }
    }
    //return shortest;
    return p;
}

