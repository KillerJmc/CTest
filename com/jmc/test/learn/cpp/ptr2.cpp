#include <iostream>
#include "tools.h"

using namespace std;

void ptr2_main()
{
    int i = 3;
    int * p_int = &i;
    //void *���Ͳ�ȷ���������޸�ֵ
    void * p_void = &i;
    cout << boolalpha;
    cout << (p_int == p_void) << endl;

    int &r_i = i;
    cout << r_i << endl;

    cout << "-----------------------------------------------";

    //���������ͣ�double[]������ָ�룬ֻ�Ǹպ���������ŵ����׵�ַ
    double a[] = { 1, 2, 3 };
    double * p_a = a;
    cout << sizeof(a) << '\t' << sizeof(p_a) << endl;
    
    //����ӷ��Ժ���ָ��
    double * p_a2 = a + 2;
    cout << p_a2 << '\t' << *p_a2 << endl;
    

}
