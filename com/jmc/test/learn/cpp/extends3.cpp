#include <iostream>
#include "tools.h"

using namespace std;

class Animal 
{
    public:
        //�麯�� ��̬��̬
        //�����������������¶���       
        //�����ͬ���ĺ��������ҿ�
        //��ͨ������ָ�������
        //�����ʻ����������
        //�е�ͬ��������
        //����javaĬ�ϸ�д��ͬ
        
        //ʵ������ʹ����������ʱ��
        //�󶨵�ַ
        
        
      //�����ã���ָ�룩���õ�
      //�麯��������ʱȷ����
      //�����õĺ�������
      //�ã���ָ�룩��ָ
      //�����ʵ������������ġ�
        virtual void eat()
        {
            cout << "�����ڳԶ���..." << endl;
        }
};

class Cat : public Animal
{
    //�̳еĺ�����дҲΪ�麯��
    //Cat��
    //vfptrָ���vftable�еĺ���
    //��ַ�仯��Animal::speak
    // -> Cat::speak
    public:
        virtual void eat()
        {
            cout << "è�ڳԶ���..." << endl;
        }
};

void extends3_main()
{ 
    Cat c;
    //�麯����Ҫ��ָ��
    //�����ò�����Ч
    Animal & a = c;
    a.eat();
    Animal * a2 = &c;
    a2->eat();
    
    Animal a3 = c;
    a3.eat();
}
