#include <iostream>
#include "tools.h"

using namespace std;

int * testStack()
{
    int i1 = 3;
    return &i1;
}

int * testHeaout_sth_endl()
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
    //��ʱ��
    int p1 = pow(2, 99);
    cout << "i1 = " << *i1 << " ���" << (*i1 == 3 ? "��ȷ" : "����") << endl;
    
    int * i2 = testHeaout_sth_endl();
    int p2 = pow(2, 999);
    cout << "i2 = " << *i2 << " ���" << (*i2 == 4 ? "��ȷ" : "����")<< endl;
    delete i2;
    
    int * i3 = testStatic();
    int p3 = pow(2, 999);
     cout << "i3 = " << *i3 << " ���" << (*i3 == 5 ? "��ȷ" : "����")<< endl;
    
}
