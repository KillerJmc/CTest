#include <iostream>
#include "../main/tools.h"

using namespace std;

//auto当作返回值！
auto add(int a, int b)
{
    return a + b;
}

//指定返回t1 + t2得到的类型
template<class T1, class T2>
auto haha(T1 t1, T2 t2) -> decltype(t1 + t2) {}

void decltype_main()
{
    int i = 3;
    //decltype返回参数类型
    decltype(i) i2 = 4;
    out_sth_endl(i, i2, add(i, i2));
    
    //获取变量类型的名称
    cout << typeid(i).name() << endl;
}

