#include <iostream>
#include "tools.h"

using namespace std;

class Base
{
    //���麯��
    //���һ�������ĳ��������ʹ��
    //��ʡ��Ϊ���麯��
    //ֻҪ��һ������
    //��������г�����
    //���಻��ʵ��������
    //Ϊ��ʵ��������
    //����Ҫ���ش˺���
    public:
        virtual void fun() = 0;
        //�������������ָ��
        //�ͷ�������󲻸ɾ�������
        /*
        virtual ~Base()
        {
            cout << "Base������������" << endl;
        }
        */
        //��������
        //Ҳ��Ҫʵ�֣���Ϊ����
        //ͨ��Ҳ���ж�����Ҫ�ͷ�
        virtual ~Base() = 0;
};

Base::~Base()
{
    cout << "Base����������������" << endl;
}

class A : public Base
{
    public:
        void fun() 
        {
            cout << "A.fun()..." << endl;
        }
        
        ~A()
        {
            cout << "A������������" << endl;
        }
};

void extends4_main()
{ 
    Base * b = new A();
    b -> fun();
    delete b;
}
