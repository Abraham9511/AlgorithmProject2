#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>

using std::fstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

const int Row = 28;
const int Col = 28;

class Image {
  private:
    string image;
    int Size;
    int Index;
  public:
    Image() {}
    void set_Index(int index) {
        Index = index;
        Size = Row*Col;
    }

    void add_Image(string ltemp) {
        image = ltemp;
    }
    int size() {
        return Size;
    }

    void print_Image() {
        cout << "-------------------------------" << endl;
        for (int i = 0; i < Row; ++i) {
            string ltemp(image.substr(i*Col, Col));
            string temp = "";
            for (int j = 0; j < Col; ++j) {
                if (ltemp[j] == 0) {
                    temp +=" ";
                } else {
                    temp += "*";
                }
            }
            if (i < 10) {
                cout << " " << i+1 << " " << temp << endl;
            } else {
                cout << i+1 << " " << temp << endl;
            }
        }
    }
};

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
    Image image_arr[60000];
    while (file.eof() != true && index < 60000) {
        image_arr[index].set_Index(index);
        int i = 0;
        char c;
        string temp = "";
        while (i < Row*Col) {
            c = file.get();
            temp += c;
            ++i;
        }
        image_arr[index].add_Image(temp);
           // image_arr[index].print_Image();
        ++index;
    }
    cout << "Choose one image to print" << endl;
    int number;
    cin >> number;
    image_arr[number].print_Image();
    file.close();
}
