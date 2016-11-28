#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<stack>

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
};

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
        std::stack<char> r_temp;
        string temp = "";
        for (int i = 0; i < Row; ++i) {
            for (int j = 0; j < Col; ++j) {
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
        image_arr[index].set_Index(index);
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
