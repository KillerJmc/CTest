#include <iostream>
#include "../main/tools.h"

using namespace std;

template<class T>
class Base 
{
    T t;
};

//必须知道父类T类型才能继承
class A : public Base<int>
{
    
};

//灵活构建
template<class T>
class B :public Base<T>
{
    T t;
};

void template3_main()
{ 
    
}
