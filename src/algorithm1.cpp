#include<utility>  // std::pair
#include<cmath>    // sqrt
#include<iostream> // 常规输入输出
#include<ctime>    // 记录时间
#include<limits>   // double最大值
#include"Image.h"  // 存储处理图像
#include<cassert>  // assert
#include"algorithm4.h"  // 快排算法实现
#include"algorithm3.h"  // 归并算法实现
#include"algorithm2.h"  // 随机算法实现
#include"algorithm1.h"  // 组织随机算法和排序算法

using std::cout;
using std::endl;

// 定义一个最大值，用于最为min的初始值
const double max_number = std::numeric_limits<double>::max();

// 私有函数
// 输入：图像一下标，图像二下标
// 输出：欧式距离
// 功能：计算两个图像的欧式距离
double Euclidean_Distance(const int &a, const int &b, Image* image_arr){
    double distance = 0;
    double* p = image_arr[a].Get_Arr();
    double* q = image_arr[b].Get_Arr();
    int size = image_arr[a].Get_Size();
    for (int i = 0; i < size; ++i) {
        distance += sqrt((p[i]-q[i])*(p[i]-q[i]));
    }
    return distance;
}

std::pair<int, int> Closet_Pair(const int& total_image, const int& each_image_size, Image* image_arr, const int& m) {
    // 声明用于存储每个图像映射到m个向量上的（int，double）点对值
    std::pair<int, double>** S = new std::pair<int, double>*[m];

    // 每个随机向量的维度应该和每个图像的大小相同
    // 映射到每个随机向量的是所有的图像
    for (int i = 0; i < m; ++i) {
        S[i] = new std::pair<int, double>[total_image];
    }

    // 用于记录随机向量生成，归并排序，快排序的时间
    double duration_random,duration_median,duration_pivot;
    clock_t f,s;
    // 运行随机向量生成算法，并记录花费时间

    std::cout << "Start Random_Projection" << std::endl;
    s = clock();
    S = Random_Projection(S, total_image, each_image_size, image_arr, m);
    f = clock();
    duration_random = f-s;
    std::cout << "Random_Projection Finish" << std::endl;

    // 声明temp用于保存可能的临时最近对，cp用于保存最终的答案，cp1用于Media的排序，cp2用于Pivot排序,min用于保存目前的最近对的欧式距离
    std::pair<int, int>temp;
    std::pair<int, int>cp1;
    std::pair<int, int>cp2;;
    double min = max_number;

    s = clock();
    for (int i = 0; i < m; ++i) {
        temp = Closet_Pair_Median(S[i],total_image);
        double dist = Euclidean_Distance(temp.first, temp.second, image_arr);
        if (min > dist) {
            min = dist;
            cp1 = std::make_pair(temp.first, temp.second);
        }
    }
    f = clock();
    duration_median = f-s;

    min = max_number;
    s = clock();
    for (int i = 0; i < m; ++i) {
        temp = Closet_Pair_Pivot(S[i], total_image);
        double dist = Euclidean_Distance(temp.first, temp.second, image_arr);
        if (min > dist) {
            min = dist;
            cp2 = std::make_pair(temp.first, temp.second);
        }
    }
    f = clock();
    duration_pivot = f-s;

    // 确保两种排序的结果相同
    assert(cp1.first == cp2.first);
    assert(cp2.second == cp2.second);

    cout << "Using duration_median time is " << (duration_random+duration_median)/(CLOCKS_PER_SEC) << "s" << endl;
    cout << "Using duration_pivot time is "  << (duration_random+duration_pivot)/(CLOCKS_PER_SEC) << "s" << endl;

    // 释放空间
    for (int i = 0; i < m; ++i) {
      delete[]S[i];
    }
    delete[]S;

    return cp1;
}
