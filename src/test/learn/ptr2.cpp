#include <iostream>
#include <test/tools.h>

using namespace std;

void ptr2_main()
{
    int i = 3;
    int * p_int = &i;
    //void *类型不确定，不能修改值
    void * p_void = &i;
    cout << boolalpha;
    cout << (p_int == p_void) << endl;

    int &r_i = i;
    cout << r_i << endl;

    cout << "-----------------------------------------------";

    //数组有类型：double[]，不是指针，只是刚好数组名存放的是首地址
    double a[] = { 1, 2, 3 };
    double * p_a = a;
    cout << sizeof(a) << '\t' << sizeof(p_a) << endl;
    
    //数组加法以后是指针
    double * p_a2 = a + 2;
    cout << p_a2 << '\t' << *p_a2 << endl;
    

}
