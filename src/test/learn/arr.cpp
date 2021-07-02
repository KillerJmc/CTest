#include <iostream>
#include "tools.h"
#include <cstdio>
#include <array>

using namespace std;

void arr_main()   
{
    //int a[] = {3}也可以
    int a[] {3};
    cout << sizeof(a) / sizeof(int) << endl;
    cout << a[0] << endl;
    cout << "-----------------------------------------------";
    
    //推荐用array，比普通数组更智能
    //c++14已经支持单个大括号，推荐
    array<int, 5> b = { 1, 2, 3, 4, 5 };
    for (int i : b)
        cout << i << endl;
    cout << "-----------------------------------------------";
    
    array<int, 5> c = {};
    //交换两个数组内容
    c.swap(b);
    for (int i : c)
        cout << i << endl;
}

