#include <iostream>
#include "tools.h"

using namespace std;

class Animal
{
    public:
        int m_age;
};

//��̳У��̳�Ϊһ��ָ�������ָ��ͬһ�����ݣ����������ǹ�����ࣩ
//�ô˷���������μ̳�
class Sheep : virtual public Animal {};

class Camel : virtual public Animal {};

class Cnm : public Sheep, public Camel {};

void extends2_main()
{ 
    Cnm cnm;
    cnm.Sheep::m_age = 100;
    cnm.Camel::m_age = 200;
   
    cout << cnm.m_age << endl;
}
