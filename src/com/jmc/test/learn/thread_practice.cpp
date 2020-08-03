#include "thread_practice.h"

int main() {
    CollectCmds obj;
    thread inObj(&CollectCmds::inMsgRecvQueue3, &obj);
    thread outObj(&CollectCmds::outMsgRecvQueue3, &obj);

    inObj.join();
    outObj.join();

    system("pause");
    return 0;
}

void CollectCmds::inMsgRecvQueue() {
    for (int i = 0; i < 3000; ++i)
    {
        cout << "inMsgRecvQueue()执行，插入一个元素：" << i << endl;
        {
            //可以代替lock()&unlock()，构造时调用lock()，析构时调用unlock()
            std::lock_guard<mutex> lg(m);
            msgRecvQueue.push_back(i);
        }
    }
}

void CollectCmds::outMsgRecvQueue() {
    for (int i = 0; i < 3000; ++i)
    {
        if (!msgRecvQueue.empty())
        {
            m.lock();
            int cmd = msgRecvQueue.front();
            msgRecvQueue.pop_front();
            m.unlock();
            cout << "outMsgRecvQueue()执行，删除一个元素：" << i << endl;
        }
        else
        {
            cout << "outMsgRecvQueue()已执行，但消息队列为空！" << i << endl;
        }

    }
    cout << "end..." << endl;
}

void CollectCmds::inMsgRecvQueue2() {
    for (int i = 0; i < 3000; ++i)
    {
        cout << "inMsgRecvQueue()执行，插入一个元素：" << i << endl;
        m1.lock();
        m2.lock();
        msgRecvQueue.push_back(i);
        m2.unlock();
        m1.unlock();
    }
}

void CollectCmds::outMsgRecvQueue2() {
    for (int i = 0; i < 3000; ++i)
    {
        if (!msgRecvQueue.empty())
        {
            m2.lock();
            m1.lock();
            int cmd = msgRecvQueue.front();
            msgRecvQueue.pop_front();
            m1.unlock();
            m2.unlock();
            cout << "outMsgRecvQueue()执行，删除一个元素：" << i << endl;
        }
        else
        {
            cout << "outMsgRecvQueue()已执行，但消息队列为空！" << i << endl;
        }

    }
    cout << "end..." << endl;
}

void CollectCmds::inMsgRecvQueue3() {
    for (int i = 0; i < 3000; ++i)
    {
        cout << "inMsgRecvQueue()执行，插入一个元素：" << i << endl;
        //解决第二示例的多把锁问题：要不一起锁，要不都失败！
        std::lock(m1, m2);

        //可配合lock_guard使用，去除unlock
        //adopt_lock表示不再使用lock，采用之前语句使用的lock
        std::lock_guard<mutex> l1(m1, std::adopt_lock);
        std::lock_guard<mutex> l2(m2, std::adopt_lock);
        msgRecvQueue.push_back(i);
    }
}

void CollectCmds::outMsgRecvQueue3() {
    for (int i = 0; i < 3000; ++i)
    {
        if (!msgRecvQueue.empty())
        {
            m2.lock();
            m1.lock();
            int cmd = msgRecvQueue.front();
            msgRecvQueue.pop_front();
            m1.unlock();
            m2.unlock();
            cout << "outMsgRecvQueue()执行，删除一个元素：" << i << endl;
        }
        else
        {
            cout << "outMsgRecvQueue()已执行，但消息队列为空！" << i << endl;
        }

    }
    cout << "end..." << endl;
}

void CollectCmds::inMsgRecvQueue4() {
    for (int i = 0; i < 3000; ++i)
    {
        cout << "inMsgRecvQueue()执行，插入一个元素：" << i << endl;
        //智能锁，与Lock_guard非常相似，但功能更多，更灵活，而效率比lock_guard低一点
        //defer_lock: 延迟锁（不锁） 还有try_to_lock(初始化时尝试锁）, adopt_lock
        std::unique_lock<mutex> u(m, std::defer_lock);
        //u.try_lock(); 尝试锁，无延迟，失败后直接继续
        //if (u.owns_lock()) 或直接if(u.try_lock()) 判断是否成功

        //u.lock() u.unlock() 手动执行，但一般不用unlock
        //u.release() 所有权释放：解除m与u的关系，并返回m的指针，记得调用unlock()
        //可用u2(std::move(u1))进行所有权传递

        msgRecvQueue.push_back(i);
    }
}

void CollectCmds::outMsgRecvQueue4() {
    for (int i = 0; i < 3000; ++i)
    {
        if (!msgRecvQueue.empty())
        {
            m2.lock();
            m1.lock();
            int cmd = msgRecvQueue.front();
            msgRecvQueue.pop_front();
            m1.unlock();
            m2.unlock();
            cout << "outMsgRecvQueue()执行，删除一个元素：" << i << endl;
        }
        else
        {
            cout << "outMsgRecvQueue()已执行，但消息队列为空！" << i << endl;
        }

    }
    cout << "end..." << endl;
}

