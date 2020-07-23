#include <iostream>
#include <fstream>
#include "tools.h"

using namespace std;

class Stu 
{
    friend ostream& operator<<(ostream&, Stu);
    
    public:
        char name[64];
        int age;
};

ostream& operator<<(ostream& out, Stu stu) 
{
    return out << "������" << stu.name << '\t' << "���䣺" << stu.age << endl;
}

void file_2_main()
{ 
    //��û�й��캯����������������ʱ������ʹ�ô����Ž��ж���ĳ�ʼ��
    Stu stu{"91������", 18};
    //����ֱ��ʹ��fstream
    //����ifstream, ofstream, fstream
    //���й��췽��������дopen����
    fstream out("/sdcard/stu", ios::out | ios::binary);
    out.write((char *)&stu, sizeof(Stu));
    out.close();
    
    Stu stu2;
    fstream in("/sdcard/stu", ios::in | ios::binary);
    in.read((char *)&stu2, sizeof(Stu));
    cout << stu2;
    in.close();
}
