#include <iostream>
#include <fstream>
#include <test/tools.h>

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
    return out << "姓名：" << stu.name << '\t' << "年龄：" << stu.age << endl;
}

void file_2_main()
{ 
    //当没有构造函数等面向对象的特征时，可以使用大括号进行对象的初始化
    Stu stu{"91江先生", 18};
    //可以直接使用fstream
    //并且ifstream, ofstream, fstream
    //均有构造方法，不用写open函数
    fstream out("/sdcard/stu", ios::out | ios::binary);
    out.write((char *)&stu, sizeof(Stu));
    out.close();
    
    Stu stu2;
    fstream in("/sdcard/stu", ios::in | ios::binary);
    in.read((char *)&stu2, sizeof(Stu));
    cout << stu2;
    in.close();
}
