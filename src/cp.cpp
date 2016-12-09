//  GNU GENERAL PUBLIC LICENSE Version 3
//  Created by 庄嘉鑫 on 09/12/2016.
//  Copyright © 2016 庄嘉鑫. All rights reserved.
//
// 该项目是冯剑琳老师算法设计课的第二个项目，使用随机算法解决高维空间的最近对的寻找

#include<iostream>  // 基本的输入输出
#include<fstream>  // 文件的读入
#include<vector>
#include<cstdlib>
#include<cstring>
#include<cmath> // sqrt
#include<ctime> // 用于粗略记录程序花费的时间
#include"cp.h" // 自定义，用于处理文件转换为图像，特别是文件的头部信息
#include"Image.h"  // 自定义，用于存储读入文件转化为图像并对图像的相关操作
#include"algorithm1.h" // 自定义，随机算法，用于随机算法解决高维空间的最近对的寻找
#include"Enumeration.h" // 自定义，枚举法，用于寻找最佳的最近邻

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;




int main(int argc, char* args[]) {
    // 用于处理输入的参数格式问题，符合要求的参数形式才会被允许继续运行程序
    if (argc != 7) {
        cout << "Need Six arguments, such as" << endl;
        cout << "-n 60000 -d 784 -f train-images.idx3-ubyte" << endl;
        return -1;
    }

    int total_image;      // 文件内图像总数量
    int each_image_size;  // 每张图片的大小，单位为字节
    string file_path;     // 文件的路径
    // 以下模块从参数中获取total_image，each_image_size，file_path的内容并赋值
    for (int i = 1; i < 7; ++i) {
        if (strncmp(args[i], "-n", 2) == 0) {
            total_image = atoi(args[i+1]);
        } else if (strncmp(args[i], "-d", 2) == 0) {
            each_image_size = atoi(args[i+1]);
        } else if (strncmp(args[i], "-f", 2) == 0) {
            file_path = string(args[i+1]);
        }
    }

    // 随机投影的直线条数
    const int m = 100;

    // 在屏幕上显示：1.图像总数；2.每张图像大小；3.文件路径
    cout << "total_image: " << total_image << endl;
    cout << "each_image_size: " << each_image_size << " bytes" << endl;
    cout << "file_path: " << file_path << endl;

    // 声明用于存储图像的变量total_image个
    Image* image_arr = new Image[total_image];
    // 声明用于读取二进制读取文件变量
    ifstream file(file_path, std::ios::binary);
    // 用于将文件中的图像读取放到image_arr中
    Read_File(file, total_image, each_image_size, image_arr);

    // 定义测量程序运行时间：起点，终点
    clock_t start, finish;
    double duration;

    // 执行随机算法，使用的排序方法是归并,快拍
    // 记录时间，打印，计算出该算法得出的最近对，打印，并且打印出两张图片的*形图
    cout << "Random Projection Using Median" << endl;
    start = clock();
    std::pair<int, int> cp1 = Closet_Pair(total_image, each_image_size, image_arr, m);
    finish = clock();
    cout << "Closet set is " << cp1.first << " " << cp1.second << endl;
    cout << "When Random Projection, time costs is " << (double)(finish-start)/CLOCKS_PER_SEC << "s" << endl;
    image_arr[cp1.first].Print_Image();
    image_arr[cp1.second].Print_Image();

    // cout << "Enumeration" << endl;
    // start = clock();
    // std::vector<std::pair<int,int> >cp3 = Enumeration(image_arr, total_image);
    // finish = clock();
    // duration = (finish-start)/CLOCKS_PER_SEC;
    // cout << "When Enumeration, time costs is " << duration << "s" << endl;
    // int i = 0;
    // for (auto it = cp3.cbegin(); it != cp3.cend(); ++it) {
    //     cout << "No." << i << " Closet set is " << it->first << " " << it->second << endl;
    //     image_arr[it->first].Print_Image();
    //     image_arr[it->second].Print_Image();
    //     ++i;
    // }

    delete[]image_arr;
    file.close();
}

// 大端转小端，返回int
int Reverse_Int(const int& i) {
    unsigned char c1, c2, c3, c4;
    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;
    return ((int)(c1 << 24)+(int)(c2<< 16)+(int)(c3<<8)+c4);
}

void Read_File(const ifstream& file, const int& total_image, const int& each_image_size, Image* image_arr) {
  // 以下四个变量以及四次file.read是为了读取文件的前32个字节，获得文件的类型，图片的大小，行，列
  // 该文件是按照大端，而我使用的机器是小端的x86架构的机器，因而若是想读取正确信息，需要Reverse_Int(const int&)来得到正确的int
  // 本项目可以从参数获得信息，因而此处直接弃掉前32个字节直接进入保存图像
  int magic_number = 0;
  int number_of_images = 0;
  int n_rows = 0;
  int n_cols = 0;
  file.read((char*)&magic_number, sizeof(magic_number));
  file.read((char*)&number_of_images, sizeof(number_of_images));
  file.read((char*)&n_rows, sizeof(n_rows));
  file.read((char*)&n_cols, sizeof(n_cols));

  // magic_number = Reverse_Int(magic_number);
  // number_of_images = Reverse_Int(number_of_images);
  // n_rows = Reverse_Int(n_rows);
  // n_cols = Reverse_Int(n_cols);
  // cout << "Magic number= " << magic_number << endl;
  // cout << "Number of images= " << number_of_images << endl;
  // cout << "rows= " << n_rows << endl;
  // cout << "cols= " << n_cols << endl;

  // 每次读取一个图像each_image_size字节，并使用Image的Add_Image方法保存
  // 文件内的图像均是灰度图，一个字节表示一个像素点，且均是方图
  int rows = sqrt(each_image_size);
  int cols = rows;
  int index = 0;
  for (int index = 0; file.eof() != true && index < total_image; ++index) {
    // unsigned char !! 使用无符号避免以后符号拓展时候变成负数
    unsigned char c;
    string temp = "";
    for (int i = 0; i < each_image_size; ++i) {
            file.read((char*)&c, sizeof(c));
            temp += c;
    }
    image_arr[index].Add_Image(temp, rows, cols);
  }
}
