#include <iostream>
#include "tools.h"

using namespace std;

//throw����׳��쳣������
//��������ö��Ÿ���
//��ǿ�ƣ�Ҳ���Բ�д
//����дthrow()��ʾ���׳��κ��쳣
void divide(int a, int b) throw (int)
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






