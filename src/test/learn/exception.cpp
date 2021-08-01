#include <iostream>
#include <tools>

using namespace std;

//throw标记抛出异常的类型
//多个类型用逗号隔开
//非强制，也可以不写
//或者写throw()表示不抛出任何异常
void divide(int a, int b) noexcept(false)
{
    if (b == 0) throw a;
    cout << a / b << endl;
}

void exception_main()
{
    try 
    {
        divide(6, 2);
        divide(4, 0);
    }
    catch (int i)
    {
        cout << i << " is divided by zero!" << endl;
    }
}






