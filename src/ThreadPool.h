#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#include <event2/thread.h> // 如果需要使用多线程，可能需要引入线程支持

#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
#include <functional>
#include <queue>
#include <condition_variable>
#include <unordered_map>

// 线程池类
class ThreadPool 
{
public:
    ThreadPool(size_t threads);
    ~ThreadPool();
    void enqueue(std::function<void()> task);

private:
    void run();
    size_t m_thread_num;
    std::vector<std::thread> m_threads;
    std::queue<std::function<void()>> m_tasks;
    std::mutex m_qmutex;
    std::condition_variable m_cv;
};

#endif //_THREADPOOL_H_