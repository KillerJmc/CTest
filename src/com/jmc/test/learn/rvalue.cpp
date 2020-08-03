#include <iostream>
#include "tools.h"

using namespace std;

class str
{
    private:
        char * _value;
        int _len;
    public:
        static long moveCpy;
        static long defaultCpy;
        
        static char * initV(char * v)
        {
            char * cs = new char[strlen(v)];
            return strcpy(cs, v);
        }
        
    public:
        //ctor
        str(): _value(nullptr), _len(0) {}
        str(char * v) : _value(initV(v)), _len(strlen(v)) {}
        
        //copy
        str(const str& s): _value(initV(s._value)), _len(s._len)
        {
            defaultCpy++;
        }
        
        //move copy
        //要写noexcept才能被自动调用
        //可由vector等等自动调用
        str(str && s) noexcept : _value(s._value), _len(s._len)
        {
            moveCpy++;
            //断开指针指向
            s._len = 0;
            s._value = nullptr;
        }
        
        //assignment
        str & operator=(const str & s)
        {
            if (this != &s)
            {
                if (_value) delete _value;
                _value = initV(s._value);
                _len = s._len;
            }          
            return *this;
        }
        
        //move assignment
        //一般是用户自己调用
        str & operator=(str && s) noexcept
        {
            if (this != &s)
            {
                if (_value) delete _value;
                _value = s._value;
                _len = s._len;
                
                s._value = nullptr;
                s._len = 0;
            }          
            return *this;
        }
        
        //dtor
        ~str()
        {
            if (_value) delete _value;
        }
};
long str::moveCpy = 0;
long str::defaultCpy = 0;

class normal_str
{
    private:
        char * _value;
        int _len;
        
    public:
        static long moveCpy;
        static long defaultCpy;
        
        char * initV(char * v)
        {
            char * cs = new char[strlen(v)];
            return strcpy(cs, v);
        }
        
    public:
        //ctor
        normal_str(): _value(NULL), _len(0) {}
        normal_str(char * v) : _value(initV(v)), _len(strlen(v)) {}
        
        //copy
        normal_str(const normal_str & s): _value(initV(s._value)), _len(s._len) 
        {
            defaultCpy++;
        }
        
        //assignment
        normal_str & operator=(const normal_str & s)
        {
            if (this != &s)
            {
                if (_value) delete _value;
                _value = initV(s._value);
                _len = s._len;
            }          
            return *this;
        }
        
        //dtor
        ~normal_str()
        {
            if (_value) delete _value;
        }
};
long normal_str::moveCpy = 0;
long normal_str::defaultCpy = 0;

template<class S>
void statistics(S& s)
{
    cout << "moveCpy = " << s.moveCpy << "\ndefaultCpy = " << s.defaultCpy << endl;
}

void testMove()
{
    vector<int> v1, v2, v3;
    for (int i = 0; i < 3000000; i++)
    {
        v1.push_back(i);
    }
    
    timer([v1, v2]() mutable {
        v2 = vector<int>(v1);
    }, "normal");
    
    timer([v1, v3]() mutable {
        v3 = vector<int>(move(v1));
    }, "move");
    
    timer([v2, v3]() mutable {
        v2.swap(v3);
    }, "swap");
}

//move对vector影响最大
//deque如果从中间插入也会有很大影响
//其他容器插入效率几乎不受影响
void testMovableStr()
{
    vector<str> movable;
    vector<normal_str> unmovable;
    char buf[] = "haha";

    timer([unmovable, buf]() mutable {
        for (int i = 0; i < 3000000; i++)
            unmovable.emplace_back(buf);
        statistics(unmovable[0]);

    }, "unmovable");

    timer([movable, buf]() mutable {
        for (int i = 0; i < 3000000; i++)
            movable.emplace_back(buf);
        statistics(movable[0]);
    }, "movable");
}

void rvalue_main()
{
    testMove();
    testMovableStr();
}
