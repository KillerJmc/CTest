#include <iostream>
#include <test/tools.h>

using namespace std;

template<class T>
class Stu;
template<class T>
void printName2(Stu<T>& stu)
{
    cout << stu.name << endl;
}

template<class T = string>
class Stu
{
    public:
        T name;
        
        //友元函数类内实现
        //（实质是全局函数）
        friend void printName(Stu<T>& stu)
        {
            cout << stu.name << endl;
        }
        
        //以上代码等效于
        friend void printName2<>(Stu<T> &);
        //注：因为实现的是函数模板
        //声明的是普通函数
        //所以要加空模板参数列表
        //将声明改成函数模板
        //并且要提前写全局函数
        //让编译器识别
};

void template4_main()
{ 
    Stu<> s = {"Jmc"};
    printName(s);
    printName2(s);
}
