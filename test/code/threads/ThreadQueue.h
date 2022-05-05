//◦
#pragma once
#include <mutex>
#include <thread>
#include <condition_variable>
#include <list>


bool isHaveElement = false;
class Queue
{
    std::condition_variable _cond;
    std::mutex lockQueue;
    std::list<int> _queue;

public:
    void push2(int value)
    {
        std::lock_guard<std::mutex> lk(lockQueue);
        _queue.push_front(value);
        _cond.notify_one();

    }

    void push(int value)
    {
        std::lock_guard<std::mutex> lk(lockQueue);
        _queue.push_back(value);
    }
    int pop()
    {
        std::lock_guard<std::mutex> lk(lockQueue);
        int result = _queue.back();






        return result;
    }

    void pop2(int& result)
    {
        std::unique_lock<std::mutex> lk(lockQueue);

        bool bEmpty;
        empty(bEmpty);
        if (bEmpty)
            _cond.wait(lk, []
            {
                return isHaveElement;
            });

        result = _queue.front();
        _queue.pop_front();
    }
    void empty(bool& result)
    {
        std::lock_guard<std::mutex> lk(lockQueue);
        result = _queue.empty();
    }
};