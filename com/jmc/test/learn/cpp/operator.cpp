#include <iostream>
#include "tools.h"

using namespace std;

class Integer
{
    private:
        int _value;
        
    public:
        Integer(int value) : _value (value){}
        
        int getValue()
        {
            return this ->_value;
        }
        
        Integer operator+(const Integer & other) const
        {
            return Integer(this -> _value + other._value);
        }        
        
        //���������֧�ֺ�������
        Integer operator+(const string & i2) 
        {
            return Integer(this -> _value + atoi(i2.c_str()));
        }
    
    //i1.operator<<();
    //i1 << cout;
    ostream & operator<<(ostream & out)
    {
        return cout << getValue();
    }
    
    //ǰ��++
    Integer & operator++()
    {
        this -> _value++;
        return * this;
    }
    
    //����++(��ռλ��Ϊ����)
    Integer operator++(int)
    {
        Integer temp = *this;
        this -> _value++;
        return temp;
    }
    
    /*
    һ��������д������ָ��Ҫ�ͷ�
    ����Ҫ��д
    Integer operator=(Integer i)
    {
        _value = i.getValue();
        return *this;
    }
    */
    
    bool operator==(Integer i)
    {
        return _value == i._value;
    }
    
    //�º���(���ŵ���д��������ú���һ���������ţ�
    void operator()(string str)
    {
        cout << "���Ǹ��ʵ�" + str << endl;
    }
    
};

//ȫ�ֺ���
Integer operator-(Integer & i1, Integer & i2)
{
    return Integer(i1.getValue() - i2.getValue());
}

//�ڳ�Ա�������޷�����cout�����
//���Ա���ʹ��ȫ�ֺ���
ostream & operator<<(ostream & out, Integer i)
{
    return out << i.getValue();
}

void operator_main()
{ 
    Integer a = Integer(3);
    Integer b = 4;
    Integer c(5);
    
    operator<<(cout, a);
    cout.operator<<(endl);
    cout << a.operator+(b) << endl;
    cout << operator-(c, b) << endl;
    cout << a.operator+("10") << endl;
    a.operator<<(cout); 
    cout << endl;
    c.operator=(b);
   
    cout << "-----------------------------------------------";
    
    cout << a << endl;
    cout << (a + b) << endl;
    cout << (c - b) << endl;
    cout << (a + "10") << endl;
    a << cout << endl;
    cout << a++ << endl;
    cout << a << endl;
    cout << ++(++a) << endl;
    cout << a << endl;
    c = b;
    cout << c << endl;
    cout << boolalpha;
    cout << (c == b) << endl;
    cout << (a == c) << endl;
    
    
    Integer i = NULL;
    i("666");
}
