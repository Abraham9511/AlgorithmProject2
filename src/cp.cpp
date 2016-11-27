#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include"Image.h"
#include"algorithm1.h"
#include"Enumeration.h"

using std::fstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main(int argc, char* args[]) {
    if (argc != 7) {
        cout << "Need Six arguments" << endl;
        return -1;
    }

    int total_image = atoi(args[2]);
    int each_image_size = atoi(args[4]);
    string file_path(args[6]);

    cout << "total_image: " << total_image << endl;
    cout << "each_image_size: " << each_image_size << " bytes" << endl;
    cout << "file_path: " << file_path << endl;

    ifstream file;
    file.open(file_path.c_str(),std::fstream::in);

    int index = 0;
    Image image_arr[total_image];
    while (file.eof() != true && index < total_image) {
        image_arr[index].Set_Index(index);
        int i = 0;
        char c;
        string temp = "";
        int row,col;
        row = col = sqrt(each_image_size);
        while (i < each_image_size) {
            c = file.get();
            temp += c;
            ++i;
        }
        image_arr[index].Add_Image(temp, each_image_size, row, col);
           // image_arr[index].print_Image();
        ++index;
    }

    clock_t start, finish;
    double duration;

    // cout << "Random Projection Using Median" << endl;
    // start = clock();
    // std::pair<int, int> cp1 = Closet_Pair1(total_image, image_arr, each_image_size);
    // finish = clock();
    // duration = (finish-start)/CLOCKS_PER_SEC;
    // cout << "Closet set is " << cp1.first << " " << cp1.second << endl;
    // cout << "When Random Projection, time costs is " << duration << "s" << endl;
    // image_arr[cp1.first].Print_Image();
    // image_arr[cp1.second].Print_Image();
    //
    //
    // cout << "Random Projection Using Pivot" << endl;
    // start = clock();
    // std::pair<int, int> cp2 = Closet_Pair2(total_image, image_arr, each_image_size);
    // finish = clock();
    // duration = (finish-start)/CLOCKS_PER_SEC;
    // cout << "Closet set is " << cp2.first << " " << cp2.second << endl;
    // cout << "When Random Projection, time costs is " << duration << "s" << endl;
    // image_arr[cp2.first].Print_Image();
    // image_arr[cp2.second].Print_Image();

    cout << "Enumeration" << endl;
    start = clock();
    std::pair<int,int>cp3 = Enumeration(image_arr, total_image);
    finish = clock();
    duration = (finish-start)/CLOCKS_PER_SEC;
    cout << "When Enumeration, time costs is " << duration << "s" << endl;
    cout << "Closet set is " << cp3.first << " " << cp3.second << endl;
    image_arr[cp3.first].Print_Image();
    image_arr[cp3.second].Print_Image();

    file.close();
}
