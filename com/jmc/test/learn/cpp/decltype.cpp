#include <iostream>
#include "tools.h"

using namespace std;

//auto��������ֵ��
auto add(int a, int b)
{
    return a + b;
}

//ָ������t1 + t2�õ�������
template<class T1, class T2>
auto haha(T1 t1, T2 t2) -> decltype(t1 + t2) {}

void decltype_main()
{
    int i = 3;
    //decltype���ز�������
    decltype(i) i2 = 4;
    out_sth_endl(i, i2, add(i, i2));
    
    //��ȡ�������͵�����
    cout << typeid(i).name() << endl;
}

