#include <iostream>
#include "tools.h"

using namespace std;

template<class T>
class Stu;
template<class T>
void printName2(Stu<T>& stu)
{
    cout << stu.name << endl;
}

template<class T = string>
class Stu
{
    public:
        T name;
        
        //��Ԫ��������ʵ��
        //��ʵ����ȫ�ֺ�����
        friend void printName(Stu<T>& stu)
        {
            cout << stu.name << endl;
        }
        
        //���ϴ����Ч��
        friend void printName2<>(Stu<T> &);
        //ע����Ϊʵ�ֵ��Ǻ���ģ��
        //����������ͨ����
        //����Ҫ�ӿ�ģ������б�
        //�������ĳɺ���ģ��
        //����Ҫ��ǰдȫ�ֺ���
        //�ñ�����ʶ��
};

void template4_main()
{ 
    Stu<> s = {"Jmc"};
    printName(s);
    printName2(s);
}
