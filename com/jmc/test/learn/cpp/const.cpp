#include <iostream>
#include "tools.h"

using namespace std;

class A 
{
    //��������thisָ�������const
    int get() const;
    public: 
        //ʹ��ֻ����const���շ���ֵ
        const int & get1(int & i) {return i;}
};

void const_main()
{ 
    int num1 = 0;
    
    //const��*��ࣺ�����޸�ֵ
    const int * p_1 = &num1;
    //*p_1 = 1;
    p_1 = nullptr;
    
    //��p_1��ͬ
    int const * p_2 = &num1;
    //*p_2 = 2;
    p_2 = nullptr;
    
    //const��*�Ҳࣺ
    //�����޸�ָ�����
    int * const p_3 = &num1;
    *p_3 = 3;
    //p_3 = nullptr;
    
    //�൱��int const * const p_4;
    const int * const p_4 = &num1;
    //*p_4 = 4;
    //p_4 = nullptr;
    
    A a;
    //һ��Ҫ��const����
    const int & r_i = a.get1(num1);
    
    
    
}


