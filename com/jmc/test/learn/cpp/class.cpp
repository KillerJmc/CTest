#include <iostream>
#include "tools.h"

using namespace std;

class A
{
    private:
        string name;
        int * t = new int;

    public:
        A() {}
        A(string name);
        
        ~A();

    void printName()
    {
        cout << name << endl;
    }

    void setName(string);
    
    //返回一个引用不会创建副本
    A& returnSelf()
    {
        /*
            struct A * const this
            为this指针实质
            （如果成员函数后加const
            会变成const A * conat this)
            每个成员方法调用时都会传入
            作为第一个参数
            如调用a2的方法:
            a2.printName();相当于
            printName(&a2);
            其中printName方法的
            储存方式为struct里的
            函数指针变量
            该指针变量指向一个全局函数
        */
        return *this;
    }
};

/*
A::A(string name)
{
    this -> name = name;
}
*/

//只有构造器能用初始化参数列表
A::A(string _name) : name(_name) {}

//析构函数用于销毁对象内部资源
//（不包括本对象和static成员）
//将在delete对象指针的时候被调用
//先以代码顺序释放堆中对象再以与实例化相反顺序释放栈中对象
A::~A()
{
    cout << name << "对应的int t被释放" << endl;
    delete t;
}

void A::setName(string name)
{
    this -> name = name;
}

void class_main()
{
    //在栈内存里直接分配空间
    //自动释放，无需销毁
    A a0;
    A a = A("Jmc");
    //a.setName("Jmc");
    a.printName();
    
    A * a2 = new A("Jdd");
    a2 -> printName();
    //这里也要写引用为左值
    A & aj = a.returnSelf();
    aj.printName();
    
    //销毁对象
    //auto和auto *没区别
    auto * a3 = new A("A3");
    delete a3;
    delete a2;
  

}
