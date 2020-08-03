#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

class CollectCmds
{
public:
    void inMsgRecvQueue();
    void outMsgRecvQueue();

    void inMsgRecvQueue2();
    void outMsgRecvQueue2();

    void inMsgRecvQueue3();
    void outMsgRecvQueue3();

    void inMsgRecvQueue4();
    void outMsgRecvQueue4();

private:
    list<int> msgRecvQueue;
    mutex m;
    mutex m1, m2;
};

int t_p_main();