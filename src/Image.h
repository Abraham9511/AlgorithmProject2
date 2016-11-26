#ifndef _IMAGE_H
#define _IMAGE_H

class Image {
  public:
    Image();
    void Set_Index(const int&);
    void Add_Image(const std::string&, const int&, const int&, const int&);
    void Trans_Int();
    int* Get_Arr();
    int Get_Size();
    int Get_Row();
    int Get_Col();
    const std::string& Get_Image();
    double Multiply(double*);
    void Print_Image();
  private:
    std::string image;
    int* Arr;
    int Size;
    int Index;
    int Row;
    int Col;
};

#endif
