#ifndef _IMAGE_H
#define _IMAGE_H

#include<string>

// 存储一张图像
// 只能用于处理灰度图
class Image {
  public:
    Image();
    ~Image();
    // 输入：一维图像（从左到右），图像的宽度和高度
    // 输出：无
    // 功能：保存到类中
    void Add_Image(const std::string& temp, const int& rows, const int&cols);
    // 输入：无
    // 输出：一维double数组
    // 功能：获取图像的一维double
    double* Get_Arr();
    // 输入：无
    // 输出：一维double字符串
    // 功能：获取一维字符串图像
    const std::string& Get_Image();
    // 输入：无
    // 输出：图像的大小
    // 功能：获取图像大小
    int Get_Size();
    // 获取图像的宽度和高度
    int Get_Row();
    int Get_Col();
    // 输入：一维长度与图像相同的向量
    // 输出：相乘结果
    // 功能：向量点乘结果
    double Multiply(double*);
    // 输入：一维长度与图像相同的向量
    // 输出：相乘结果
    // 功能：打印对应的图片
    void Print_Image();
  private:
    // 灰度图，一个字节就能表示一个像素点的值
    std::string image;
    // 将字符串模式的像素点转为整数 “12” -> int类型的12
    double* Arr;
    // 图像的宽度高度
    int Row;
    int Col;
    // 将一维字符串转换为一维double
    void Trans_Double();
};

#endif
