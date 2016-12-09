#ifndef _ALGORITHM_1_
#define _ALGORITHM_1_

#include<string>
#include<utility>
#include"Image.h"

// 输入：图像总数量，图像大小，图像数组指针，随机向量的数量
// 输出：该随机算法下的最近对
// 功能：使用随机算法求解高维空间下的最近对问题
std::pair<int, int> Closet_Pair(const int& total_image, const int& each_image_size, Image* image, const int& m);

#endif
