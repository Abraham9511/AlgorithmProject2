#ifndef _ALGORITHM_3_
#define _ALGORITHM_3_

#include<string>
#include<utility>
#include"Image.h"

// 输入：所有图像投影到同意随机向量后的随机向量，
// 输出：该直线上的最近对的下标
// 功能：使用归并排序返回直线上最近对的下标
std::pair<int, int> Closet_Pair_Median(std::pair<int, double>* list);

#endif
