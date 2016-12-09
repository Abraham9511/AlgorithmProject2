#include<string>
#include<iostream>
#include<cstdlib>
#include"Image.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Image::Image() {
  this->Arr = NULL;
}

Image::~Image() {
    if(this->Arr != NULL) {
        delete[] this->Arr;
    }
}

// 初始化图像并且生成图像的double数组方便后面计算
void Image::Add_Image(const string& temp, const int& rows, const int& cols) {
    this->image = temp;
    this->Size = rows*cols;
    this->Row = rows;
    this->Col = cols;
    this->Arr = new double[this->Get_Size()];
    this->Trans_Int();
}

void Image::Trans_Int() {
    int size = Get_Size();
    const string& temp = Get_Image();
    for (int i = 0; i < size; ++i) {
        this->Arr[i] = (unsigned char)(temp.c_str()[i]);
    }
}

double* Image::Get_Arr() {
    return this->Arr;
}

int Image::Get_Size() {
    return (this->Get_Row())*(this->Get_Col());
}

int Image::Get_Row() {
    return this->Row;
}

int Image::Get_Col() {
    return this->Col;
}

const string& Image::Get_Image() {
    return this->image;
}

double Image::Multiply(double* a) {
    double ans;
    int size = Get_Size();
    const string& temp = Get_Image();
    const double* p = Get_Arr();
    for (int i = 0; i < size; ++i) {
        ans += a[i]* p[i];
    }
    return ans;
}

// 格式化打印图像
// 一个unsigned char的取值是0-255，我们认为所有只要不是0，就输出“ ”，否则输出”*“
void Image::Print_Image() {
  cout << "-------------------------------" << endl;
  for (int i = 0; i < Row; ++i) {
      string ltemp(image.substr(i*Col, (i+1)*Col));
      string temp = "";
      for (int j = 0; j < Col; ++j) {
          if (ltemp[j] != 0b00000000) {
              temp +=" ";
          } else {
              temp += "*";
          }
      }
      if (i < 9) {
          cout << " " << i+1 << " " << temp << endl;
      } else {
          cout << i+1 << " " << temp << endl;
      }
  }
}
