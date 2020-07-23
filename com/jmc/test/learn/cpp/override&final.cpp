#include <iostream>
#include "tools.h"

using namespace std;

class Base 
{
    virtual void ok() {}
};

class A : public Base
{
    //告诉编译器这是要重载的函数，
    //而不是一个新的虚函数
    virtual void ok() override 
    {
        cout << "A: ok" << endl;
    }
};

class B final
{
    virtual void haha() final {}
};

/* 不能继承终类和终虚函数
class C : public B
{
    virtual void haha() {}
};
*/



void override_and_final_main()
{
    
}
