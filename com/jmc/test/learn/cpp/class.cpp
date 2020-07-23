#include <iostream>
#include "tools.h"

using namespace std;

class A
{
    private:
        string name;
        int * t = new int;

    public:
        A() {}
        A(string name);
        
        ~A();

    void printName()
    {
        cout << name << endl;
    }

    void setName(string);
    
    //����һ�����ò��ᴴ������
    A& returnSelf()
    {
        /*
            struct A * const this
            Ϊthisָ��ʵ��
            �������Ա�������const
            ����const A * conat this)
            ÿ����Ա��������ʱ���ᴫ��
            ��Ϊ��һ������
            �����a2�ķ���:
            a2.printName();�൱��
            printName(&a2);
            ����printName������
            ���淽ʽΪstruct���
            ����ָ�����
            ��ָ�����ָ��һ��ȫ�ֺ���
        */
        return *this;
    }
};

/*
A::A(string name)
{
    this -> name = name;
}
*/

//ֻ�й��������ó�ʼ�������б�
A::A(string _name) : name(_name) {}

//���������������ٶ����ڲ���Դ
//���������������static��Ա��
//����delete����ָ���ʱ�򱻵���
//���Դ���˳���ͷŶ��ж���������ʵ�����෴˳���ͷ�ջ�ж���
A::~A()
{
    cout << name << "��Ӧ��int t���ͷ�" << endl;
    delete t;
}

void A::setName(string name)
{
    this -> name = name;
}

void class_main()
{
    //��ջ�ڴ���ֱ�ӷ���ռ�
    //�Զ��ͷţ���������
    A a0;
    A a = A("Jmc");
    //a.setName("Jmc");
    a.printName();
    
    A * a2 = new A("Jdd");
    a2 -> printName();
    //����ҲҪд����Ϊ��ֵ
    A & aj = a.returnSelf();
    aj.printName();
    
    //���ٶ���
    //auto��auto *û����
    auto * a3 = new A("A3");
    delete a3;
    delete a2;
  

}
