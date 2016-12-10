#ifndef _ENUMERATION_H_
#define _ENUMERATION_H_

#include "Image.h"
#include <utility>
#include <vector>

const int BACK = 10;

//输入：所有图像，图像的数量
//输出：前BACK个最优的解
//功能：使用暴力枚举算法找出最优的那些解，验证投影算法的准确度
std::vector<std::pair<int, int> >Enumeration(Image* image, const int& image_size);


#endif
