#include <iostream>
#include "tools.h"

using namespace std;

template<class T>
void fun()
{
    cout << "fun()..." << endl;
}

template<class T>
void add(T a, T b)
{
    cout << a + b << endl;
}

template<class T>
void out_sth_endl(T a)
{
    cout << "����ģ��" << endl;
}

void out_sth_endl(int a)
{
    cout << "��ͨ����" << endl;
}

class Person 
{
    public:
        int id;
};

template<class T>
bool equals(T& a, T& b)
{
    return a == b;
}

//�ṩ���廯��ģ�壬�����ȵ���
template<> bool equals(Person& p1, Person& p2)
{
    return p1.id == p2.id;
}

void template_main()
{ 
    //�����������ָ������
    fun<int>();
    
    int a = 3;
    char c = 'c';
    //�Զ������Ƶ���
    //������ʽ����ת����
    //add(a, c);
    
    //��ʾָ������
    //�ᷢ����ʽ����ת��
    add<int>(a, c);
    
    int i = 3;
    //��ͨ��������ʵ��ʱ
    //���ȵ�����ͨ����
    out_sth_endl(i);
    //ǿ��ʹ�ú���ģ�壺
    //ͨ����ģ������б�
    //<>(i);
    
    //���÷�������ת�������ȵ�
    //����ģ��
    c = 'c';
    out_sth_endl(c);
    
    //��ò�Ҫͬʱдͬ����ͨ�����ͺ���ģ�壡
    
    Person p1 = {10};
    Person p2 = {20};
    Person p3 = {10};
    //��������"==">�����
    cout << equals(p1, p2) << endl;
    cout << equals(p1, p3) << endl;
    
}
