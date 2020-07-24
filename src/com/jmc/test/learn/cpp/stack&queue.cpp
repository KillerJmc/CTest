#include <iostream>
#include "tools.h"

using namespace std;

void stackk()
{ 
    //栈：先进后出
    stack<int> s;
    for (int i = 0; i < 5; i++)
        s.push((i + 1) * 10);
    
    cout << s.size() << endl;
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << s.size() << endl;
    cout << "-----------------------------------------------";
}

void queuee()
{
    //队列：先进先出
    queue<int> q;
    for (int i = 0; i < 5; i++)
        q.push((i+1)*10);
    
    cout << q.size() << endl;
    while(!q.empty())
    {
        cout << "队头: " << q.front() << endl;
        cout << "队尾: " << q.back() << endl;
        q.pop();
    }
    cout << q.size() << endl;
}

void stack_and_queue_main()
{
    stackk();
    queuee();
}
