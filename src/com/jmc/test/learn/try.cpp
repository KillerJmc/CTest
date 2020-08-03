#include <iostream>
#include "tools.h"

using namespace std;

//可以声明抛出异常类型(可多个，逗号分开)
//也可以声明throw()表示不抛出任何异常
//也可以什么都不写表示会抛出任何异常
int divide_(int a, int b) noexcept(false)
{
    if (b == 0) throw a;
    return a / b;
}

void try_main()
{
    try 
    {
        cout << divide_(18, 2) << endl;
        cout << divide_(3, 0) << endl;
        cout << divide_(10, 3) << endl;
    } 
    catch (int e)
    {
        cout << e << " devides by zero!" << endl;
    }
}






