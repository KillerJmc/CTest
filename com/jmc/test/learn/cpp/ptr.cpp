#include <iostream>

using namespace std;

/**
    ָ����������ͷ�
*/
void ptr_main()
{
    int * p1 = new int;
    int * p2 = (int *)malloc(sizeof(int));
    //ɾ�������ڴ�����
    delete p1;
    free(p2);  
    //��ֵΪNULL�����ظ�ɾ������������
    p1 = NULL;
    p2 = NULL;
}