#include <iostream>
#include "tools.h"

using namespace std;

//��ģ���ģ������б������Ĭ�ϲ���
template<class NameType = string, class AgeType = int>
class Stu 
{
    public:
        NameType name;
        AgeType age;
        
        /*void print()
        {
            cout << name << age << endl;
    
        }*/
        
        void print();
        
        void f()
        {
            //��������ʱ�Ż��ж��Ƿ��
            //�����в����ñ����ͨ��
            name.fuck();
        }
};

//����ʵ��
template<class T, class R>
void Stu<T, R>::print()
{
    cout << name << age << endl;
}

template<class T, class R>
void print1(Stu<T, R>& stu)
{
    stu.print();
    cout << typeid(T).name() << endl;
    cout << typeid(R).name() << endl;
}

void print2(Stu<string, string> & stu)
{
    stu.print();
}

template<class T>
void print3(T t)
{
    t.print();
}


void template2_main()
{ 
    //��ģ��ֻ������ʾָ�����ͷ�ʽ
    Stu<string> s1{"Jmc", 18};
    print1(s1);
    
    Stu<> s0{"Wah", 666};
    print3(s0);
    
    Stu<string, string> s2{"Jmp", "20"};
    print2(s2);
}
