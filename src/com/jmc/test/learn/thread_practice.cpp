#include "thread_practice.h"

int main() {
    CollectCmds obj;
    thread inObj(&CollectCmds::inMsgRecvQueue, &obj);
    thread outObj(&CollectCmds::outMsgRecvQueue, &obj);

    inObj.join();
    outObj.join();

    return 0;
}

void CollectCmds::inMsgRecvQueue() {
    for (int i = 0; i < 1000000; ++i) {
        msgRecvQueue.push_back(i);
        cout << "inMsgRecvQueue()执行，插入一个元素：" << i << endl;
    }
}

void CollectCmds::outMsgRecvQueue() {
    for (int i = 0; i < 100000; ++i) {
        if (!msgRecvQueue.empty())
        {
            int cmd = msgRecvQueue.front();
            msgRecvQueue.pop_front();
        }
        else
        {
            cout << "outMsgRecvQueue()已执行，但消息队列为空！" << i << endl;
        }

        cout << "end..." << endl;
    }
}

