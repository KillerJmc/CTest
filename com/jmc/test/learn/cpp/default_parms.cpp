#include <iostream>
#include "tools.h"

using namespace std;

//�ں���ԭ����дĬ�ϲ���
//���ҵ����ȡĬ�ϲ��������ܼ��
void get(int = 3, int = 4, int = 5);

void default_parms_main()
{
    get(1);
}

void get(int a, int b, int c)
{
    printf("%d    %d    %d", a, b, c);
}

