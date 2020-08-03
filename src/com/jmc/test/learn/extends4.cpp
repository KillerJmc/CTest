#include <iostream>
#include "tools.h"

using namespace std;

class Base
{
    //纯虚函数
    //解决一般基类内某函数不被使用
    //可省略为纯虚函数
    //只要有一个纯虚
    //函数的类叫抽象类
    //该类不能实例化对象
    //为了实例化对象
    //子类要重载此函数
    public:
        virtual void fun() = 0;
        //虚析构解决父类指针
        //释放子类对象不干净的问题
        /*
        virtual ~Base()
        {
            cout << "Base析构函数调用" << endl;
        }
        */
        //纯虚析构
        //也需要实现，因为父类
        //通常也会有对象需要释放
        virtual ~Base() = 0;
};

Base::~Base()
{
    cout << "Base纯虚析构函数调用" << endl;
}

class A1 : public Base
{
    public:
        void fun()
        {
            cout << "A1.fun()..." << endl;
        }

        ~A1()
        {
            cout << "A析构函数调用" << endl;
        }
};

void extends4_main()
{
    Base * b = new A1();
    b -> fun();
    delete b;
}
