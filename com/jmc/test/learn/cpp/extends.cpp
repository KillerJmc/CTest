#include <iostream>
#include "tools.h"

using namespace std;

typedef string s;

class Base {
    public:
        s p1 = "public";
        static int sta;
    protected:
        s p2 = "protected";
    private:
        s p3 = "private";
};

int Base::sta = 3;

//�����̳У�����������˽�м̳�

//�ɷ��ʸ���public, protected, static ����
//Ȩ�޲���
//�̳����зǾ�̬��Ա
//˽�����Ա������������޷�����
class Aa : public Base {
    public:
        static int sta;
};

int Aa::sta = 10;

//������public, protected, static����ת��Ϊ
//protected���ݴ���
class B : protected Base{};

//������public, portected, static����ת��Ϊ
//private���ݴ���
class C : private Base{};

class What : public Aa, protected B, private C{};

void extends_main()
{ 
    Aa a; B b; C c;
    //ע�⣺������������븸��ͬ���ĺ����ȣ�������ڴ˺��������к����ᱻ���������أ�����Ժ�Ĭ�ϵ�������ú�������ʹ���������غ���Ҳ���ʲ��ˣ�����Ҫ����������øú�������������Ĭ�ϵ���������ԣ�Ҳ���ü��������Է��ʸ�������
    
    cout << a.sta << endl;
    //���ʸ��������Ҫ��������
    //��ʾ����a��Base������
    //�µ�sta����
    cout << a.Base::sta << endl;
    cout << Aa::sta << endl;
              //ͨ��������ʽ���ʣ�ͨ���������������
    cout << Aa::Base::sta << endl;
}
