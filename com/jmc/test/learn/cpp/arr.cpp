#include <iostream>
#include "tools.h"
#include <cstdio>
#include <array>

using namespace std;

void arr_main()   
{
    //int a[] = {3}Ҳ����
    int a[] {3};
    cout << sizeof(a) / sizeof(int) << endl;
    cout << a[0] << endl;
    cout << "-----------------------------------------------";
    
    //�Ƽ���array������ͨ���������
    //c++14�Ѿ�֧�ֵ��������ţ��Ƽ�
    array<int, 5> b = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << endl;
    cout << "-----------------------------------------------";
    
    array<int, 5> c = {};
    //����������������
    c.swap(b);
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << endl;
}

