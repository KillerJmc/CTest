#include <iostream>
#include "tools.h"

using namespace std;

int * testStack()
{
    int i1 = 3;
    return &i1;
}

int * testHeap()
{
    int * i2 = new int(4);
    return i2;
}

int * testStatic()
{
    static int i3 = 5;
    return &i3;
}

void memory_main()
{
    int * i1 = testStack();
    //拖时间
    int p1 = pow(2, 99);
    cout << "i1 = " << *i1 << " 结果" << (*i1 == 3 ? "正确" : "错误") << endl;

    int * i2 = testHeap();
    int p2 = pow(2, 999);
    cout << "i2 = " << *i2 << " 结果" << (*i2 == 4 ? "正确" : "错误")<< endl;
    delete i2;
    
    int * i3 = testStatic();
    int p3 = pow(2, 999);
     cout << "i3 = " << *i3 << " 结果" << (*i3 == 5 ? "正确" : "错误")<< endl;
    
}
