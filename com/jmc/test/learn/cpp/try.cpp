#include <iostream>
#include "tools.h"

using namespace std;

//���������׳��쳣����(�ɶ�������ŷֿ�)
//Ҳ��������throw()��ʾ���׳��κ��쳣
//Ҳ����ʲô����д��ʾ���׳��κ��쳣
int divide(int a, int b) throw (int)
{
    if (b == 0) throw a;
    return a / b;
}

void try_main()
{
    try 
    {
        cout << divide(18, 2) << endl;
        cout << divide(3, 0) << endl;
        cout << divide(10, 3) << endl;
    } 
    catch (int e)
    {
        cout << e << " devides by zero!" << endl;
    }
}






