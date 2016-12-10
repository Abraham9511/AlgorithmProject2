#include<iostream> //常规输入输出
#include<cassert>  // assert
#include<cmath>    // sqrt
#include<random>   // randowm
#include<ctime>    // null
#include<cstdlib>  // size_t
#include"Image.h"  // 处理图像
#include"algorithm2.h"

using std::cin;
using std::cout;
using std::endl;

// 定义常量
const double twopi = double(2.0 * 3.14159265358979323846);

// 私有函数
// 输入：保存随机向量，随机向量的长度（必须是偶数）
// 输出：无
// 功能：通过boxmuller算法以及知乎上参考某大大的改良版本，生成偶数长度的随机向量
void boxmuller(double* data, size_t count){
    assert(count % 2 == 0);

    // 随机的种子是当前时间
    srand((unsigned)time(NULL));
    double u1,u2, radius, theta;
    for (size_t i = 0; i < count; i += 2) {
        u1 = 1.0f - rand()/((double)(RAND_MAX)); // [0, 1) -> (0, 1]
        u2 = rand()/((double)(RAND_MAX));
        radius = std::sqrt(-2 * std::log(u1));
        theta = twopi * u2;
        data[i] = radius * std::cos(theta);
        data[i+1] = radius * std::sin(theta);
    }
}

std::pair<int,double>** Random_Projection(std::pair<int, double>**S, const int& total_image, const int& each_image_size, Image* image_arr, const int& m) {
  // 声明用于保存m个随机向量，长度等长图片的长度
    double **a = new double*[m];
    for (int i = 0; i < m; ++i) {
      a[i] = new double[each_image_size];
    }

    // 生成随机向量
    for (int i = 0; i < m; ++i) {
        boxmuller(a[i], each_image_size);
    }

    // 投影到mge随机向量
    for (int i = 0; i < total_image; ++i) {
        for (int j = 0; j < 100; ++j) {
            S[j][i].first = i;
            S[j][i].second = image_arr[i].Multiply(a[j]);
        }
    }

    // 释放空间
    for (int i = 0; i < m; ++i) {
      delete[] a[i];
    }
    delete[]a;
    return S;
}
