#include <iostream>
#include <tools>

using namespace std;

class Integer
{
    private:
        int _value;
        
    public:
        Integer(int value) : _value (value){}
        
        int getValue()
        {
            return this -> _value;
        }
        
        Integer operator+(const Integer & other) const
        {
            return Integer(this -> _value + other._value);
        }        
        
        //运算符重载支持函数重载
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
    
    //前置++
    Integer & operator++()
    {
        this -> _value++;
        return * this;
    }
    
    //后置++(有占位符为后置)
    Integer operator++(int)
    {
        Integer temp = *this;
        this -> _value++;
        return temp;
    }
    
    /*
    一般无需重写，若有指针要释放
    则需要重写
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
    
    //仿函数(括号的重写，就像调用函数一样调用括号）
    void operator()(string str)
    {
        cout << "这是个彩蛋" + str << endl;
    }
    
};

//全局函数
Integer operator-(Integer & i1, Integer & i2)
{
    return Integer(i1.getValue() - i2.getValue());
}

//在成员函数中无法做到cout在左边
//所以必须使用全局函数
ostream & operator<<(ostream & out, Integer i)
{
    return out << i.getValue();
}

void operator_main()
{ 
    auto a = Integer(3);
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
    
    
    Integer i = 0;
    i("666");
}
