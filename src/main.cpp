#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include"Image.h"
#include"algorithm1.h"

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

    std::pair<int, int> cp = Closet_Pair(total_image, image_arr, each_image_size);
    cout << "Closet set is " << cp.first << " " << cp.second << endl;
    image_arr[cp.first].Print_Image();
    image_arr[cp.second].Print_Image();
    file.close();
}
