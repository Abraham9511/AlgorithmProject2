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

int Reverse_Int(int i) {
    unsigned char c1, c2, c3, c4;
    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;
    return ((int)(c1 << 24)+(int)(c2<< 16)+(int)(c3<<8)+c4);
}

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

    ifstream file(file_path, std::ios::binary);
    //file.open(file_path.c_str(),std::fstream::in);
    int magic_number = 0;
    int number_of_images = 0;
    int n_rows = 0;
    int n_cols = 0;
    unsigned char label;

    file.read((char*)&magic_number, sizeof(magic_number));
    file.read((char*)&number_of_images, sizeof(number_of_images));
    file.read((char*)&n_rows, sizeof(n_rows));
    file.read((char*)&n_cols, sizeof(n_cols));

    magic_number = Reverse_Int(magic_number);
    number_of_images = Reverse_Int(number_of_images);
    n_rows = Reverse_Int(n_rows);
    n_cols = Reverse_Int(n_cols);

    cout << "Magic number= " << magic_number << endl;
    cout << "Number of images= " << number_of_images << endl;
    cout << "rows= " << n_rows << endl;
    cout << "cols= " << n_cols << endl;

    int index = 0;
    Image image_arr[60000];
    while (file.eof() != true && index < 60000) {
        int i = 0;
        unsigned char c;
       // std::stack<char> r_temp;
        string temp = "";
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                file.read((char*)&c, sizeof(c));
                temp += c;
                //r_temp.push(c);
            }
            /*
            while(r_temp.empty() == false) {
                temp += r_temp.top();
                r_temp.pop();
            }
            */
        }
        image_arr[index].Set_Index(index);
        image_arr[index].Add_Image(temp,each_image_size, n_rows, n_cols);
           // image_arr[index].print_Image();
        ++index;
    }

    clock_t start, finish;
    double duration;

    cout << "Random Projection Using Median" << endl;
    start = clock();
    std::pair<int, int> cp1 = Closet_Pair1(total_image, image_arr, each_image_size);
    finish = clock();
    duration = (finish-start)/CLOCKS_PER_SEC;
    cout << "Closet set is " << cp1.first << " " << cp1.second << endl;
    cout << "When Random Projection, time costs is " << duration << "s" << endl;
    image_arr[cp1.first].Print_Image();
    image_arr[cp1.second].Print_Image();


    cout << "Random Projection Using Pivot" << endl;
    start = clock();
    std::pair<int, int> cp2 = Closet_Pair2(total_image, image_arr, each_image_size);
    finish = clock();
    duration = (finish-start)/CLOCKS_PER_SEC;
    cout << "Closet set is " << cp2.first << " " << cp2.second << endl;
    cout << "When Random Projection, time costs is " << duration << "s" << endl;
    image_arr[cp2.first].Print_Image();
    image_arr[cp2.second].Print_Image();
    
    cout << "Enumeration" << endl;
    start = clock();
    std::vector<std::pair<int,int> >cp3 = Enumeration(image_arr, total_image);
    finish = clock();
    duration = (finish-start)/CLOCKS_PER_SEC;
    cout << "When Enumeration, time costs is " << duration << "s" << endl;
    int i = 0;
    for (auto it = cp3.cbegin(); it != cp3.cend(); ++it) {
        cout << "No." << i << " Closet set is " << it->first << " " << it->second << endl;
        image_arr[it->first].Print_Image();
        image_arr[it->second].Print_Image();
        ++i;
    }

    file.close();
}
