#include <iostream>
#include "tools.h"

using namespace std;

template<class T>
class Base 
{
    T t;
};

//����֪������T���Ͳ��ܼ̳�
class A : public Base<int>
{
    
};

//����
template<class T>
class B :public Base<T>
{
    T t;
};

void template3_main()
{ 
    
}
