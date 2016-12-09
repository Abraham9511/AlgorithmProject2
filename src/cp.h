#ifndef _CP_H_
#define _CP_H_

#include<iostream>
#include<fstream>
#include"Image.h"

// 输入：大端模式的int
// 输出：小端模式的int
// 功能：用于大端转小端
int Reverse_Int(const int& i);
// 输入：未处理的文件fstream,图像总数量，每张图片大小，保存图像数组指针
// 输出：无，通过image_arr指针传回需要的图像
// 功能：除去文件的头部信息并正确将文件读入图像数组
void Read_File(const ifstream& file, const int& total_image, const int& each_image_size, Image* image_arr)；

#endif
