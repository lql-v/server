#pragma once
#include <event2/thread.h> // 如果需要使用多线程，可能需要引入线程支持

#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
#include <functional>
#include <queue>
#include <condition_variable>
#include <unordered_map>

/**
 * @class 线程池
 */
class ThreadPool 
{
public:
    /**
     * @brief 构造函数
     * @param[in] threads 启动线程数
     */   
    ThreadPool(size_t threads);
    ~ThreadPool();
    /**
     * @brief 任务入队
     * @param[in] task 向任务队列增加任务
     */   
    void enqueue(std::function<void()> task);

private:
    void run();                                     // 运行
    size_t m_thread_num;                            // 线程数
    std::vector<std::thread> m_threads;             // 线程数组
    std::queue<std::function<void()>> m_tasks;      // 任务队列
    std::mutex m_qmutex;                            // 队列锁
    std::condition_variable m_cv;                   // 条件变量
};
