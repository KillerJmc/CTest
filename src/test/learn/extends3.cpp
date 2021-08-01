#include <iostream>
#include <tools>

using namespace std;

class Animal 
{
    public:
        //虚函数 动态多态
        //允许在派生类中重新定义       
        //与基类同名的函数，并且可
        //以通过基类指针或引用
        //来访问基类和派生类
        //中的同名函数。
        //即和java默认覆写相同
        
        //实际上是使函数在运行时才
        //绑定地址
        
        
      //用引用（或指针）调用的
      //虚函数在运行时确定，
      //被调用的函数是引
      //用（或指针）所指
      //对象的实际类型所定义的。
        virtual void eat()
        {
            cout << "动物在吃东西..." << endl;
        }
};

class Cat : public Animal
{
    //继承的函数重写也为虚函数
    //Cat中
    //vfptr指向的vftable中的函数
    //地址变化：Animal::speak
    // -> Cat::speak
    public:
        virtual void eat()
        {
            cout << "猫在吃东西..." << endl;
        }
};

void extends3_main()
{ 
    Cat c;
    //虚函数需要用指针
    //或引用才能生效
    Animal & a = c;
    a.eat();
    Animal * a2 = &c;
    a2-> eat();
    
    Animal a3 = c;
    a3.eat();
}
