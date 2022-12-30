#include <iostream>
#include <test/tools.h>

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
        Person() : m_bedroom("卧室"){}
};

void Lover::comeIn(Person * p)
{
    cout << "我老婆进了我的" << p -> m_bedroom << endl;
}

class Police
{
    bool m_searchWarrent;
       
    public: 
        Police(bool  sw): m_searchWarrent(sw){}
    
        void searchHouse(Person & p)
        {
            if (m_searchWarrent)
                cout << "警察正在搜查我的" << p.m_bedroom << endl;
            else
                cout << "无搜查令！" << endl;
        }
};

void goodGay(Person & p)
{
    cout << "好基友正在访问我的" << p.m_bedroom << endl;
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
