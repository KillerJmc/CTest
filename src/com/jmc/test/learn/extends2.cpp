#include <iostream>
#include "../main/tools.h"

using namespace std;

class Animal
{
    public:
        int m_age;
};

//虚继承，继承为一个指针变量，指向同一份数据（声明的类们共享基类）
//用此方法解决菱形继承
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
