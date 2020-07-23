#include <iostream>
#include "tools.h"

using namespace std;

void stackk()
{ 
    //ջ���Ƚ����
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
    //���У��Ƚ��ȳ�
    queue<int> q;
    for (int i = 0; i < 5; i++)
        q.push((i+1)*10);
    
    cout << q.size() << endl;
    while(!q.empty())
    {
        cout << "��ͷ: " << q.front() << endl;
        cout << "��β: " << q.back() << endl;
        q.pop();
    }
    cout << q.size() << endl;
}

void stack_and_queue_main()
{
    stackk();
    queuee();
}
