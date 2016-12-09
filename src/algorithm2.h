#ifndef _ALGORITHM_2_
#define _ALGORITHM_2_

#include<utility>
#include"Image.h"

// 输入：S保存所有映射到随机向量后的向量，a是随机向量
// 输出：返回所有图像投影到所有随机向量后的向量
// 功能：生成所有图像投影到所有随机向量后的向量
std::pair<int,double>** Random_Projection(std::pair<int, double>**S, const int& total_image, const int& each_image_size, Image* image_arr, const int& m);

#endif
