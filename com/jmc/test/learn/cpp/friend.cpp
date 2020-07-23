#include <iostream>
#include "tools.h"

using namespace std;

class Person;
class Lover
{
    public:
        void comeIn(Person * p);
};

class Person
{
    friend void goodGay(Person &);
    friend class Police;
    friend void Lover::comeIn(Person *);
    
    private:
        string m_bedroom;
    public:
        Person() : m_bedroom("����"){}
};

void Lover::comeIn(Person * p)
{
    cout << "�����Ž����ҵ�" << p-> m_bedroom << endl;
}

class Police
{
    bool m_searchWarrent;
       
    public: 
        Police(bool  sw): m_searchWarrent(sw){}
    
        void searchHouse(Person & p)
        {
            if (m_searchWarrent)
                cout << "���������Ѳ��ҵ�" << p.m_bedroom << endl;
            else
                cout << "���Ѳ��" << endl;
        }
};

void goodGay(Person & p)
{
    cout << "�û������ڷ����ҵ�" << p.m_bedroom << endl;
}

void friend_main()
{
    Person p;
    goodGay(p);
    
    Police po = true;
    po.searchHouse(p);
    
    Lover l;
    l.comeIn(&p);
}
