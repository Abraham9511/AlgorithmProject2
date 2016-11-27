#ifndef _IMAGE_H
#define _IMAGE_H

#include<string>
class Image {
  public:
    Image();
    void Set_Index(const int&);
    void Add_Image(const std::string&, const int&, const int&, const int&);
    void Trans_Int();
    int* Get_Arr(); // 得到Arr
    int Get_Size(); // 得到长度
    int Get_Row();
    int Get_Col();
    const std::string& Get_Image();
    double Multiply(double*);
    void Print_Image(); // 打印对应的图片
  private:
    std::string image; // 灰度图，一个字节就能表示一个像素点的值
    int* Arr; // 将字符串模式的像素点转为整数 “12” -> int类型的12
    int Size; // 长度
    int Index; // 标记image
    int Row;
    int Col; // 正方形
};

#endif
