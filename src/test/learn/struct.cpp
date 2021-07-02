#include <iostream>

using namespace std;

struct Stu
{
    string name;
    int id;
};

void set(struct Stu *);
void get(struct Stu *);
void invalidSet(struct Stu);
void struct_main()
{
    struct Stu s1 = {"Jmc", 05};
    cout << s1.name << s1.id << endl;
    struct Stu * s1_ptr = &s1;
    //s1_ptr指向s1结构体中的成员
    s1_ptr -> name = "OKSir";
    s1_ptr -> id = 6;
    cout << s1.name << s1.id << endl;
  
    invalidSet(s1);
    get(&s1);
  
    set(&s1);
    get(&s1);
}

void set(Stu* s) 
{
    s -> name = "set";
    s -> id = 0;
}

//C中传递的参数均为拷贝，无法改变原值（除非传指针)
void invalidSet(Stu s)
{
    s.name = "set";
    s.id = 0;
}

void get(Stu* s)
{
    cout << s -> name << s -> id << endl;
}
