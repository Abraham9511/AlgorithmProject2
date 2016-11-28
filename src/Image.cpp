#include<string>
#include<iostream>
#include<cstdlib>
#include"Image.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Image::Image() {}

void Image::Set_Index(const int& index) {
    this->Index = index;
}

void Image::Add_Image(const string& ltemp, const int& m, const int& row, const int& col) {
    this->image = ltemp;
    this->Size = m;
    this->Row = row;
    this->Col = col;
    this->Arr = new int[m];
    Trans_Int();
}

void Image::Trans_Int() {
    int m = Get_Size();
    const string& temp = Get_Image();
    for (int i = 0; i < m; ++i) {
        this->Arr[i] = atoi(&temp.c_str()[i]);
    }
}

int* Image::Get_Arr() {
    return this->Arr;
}

int Image::Get_Size() {
    return this->Size;
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
    const int* p = Get_Arr();
    for (int i = 0; i < size; ++i) {
        ans += a[i]* p[i];
    }
    return ans;
}

void Image::Print_Image() {
  cout << "-------------------------------" << endl;
  //cout << image << endl;
  for (int i = 0; i < Row; ++i) {
      string ltemp(image.substr(i*Col, (i+1)*Col));
      string temp = "";
      for (int j = 0; j < Col; ++j) {
          if (ltemp[j] == 0b00000000) {
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
