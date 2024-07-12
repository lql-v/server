#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t threads) : m_thread_num(threads) 
{
    for (size_t i=0; i<threads; ++i)
    {
        m_threads.emplace_back([this] { run(); });
    }
}

ThreadPool::~ThreadPool()
{
    for (auto &thread : m_threads) 
    {
        thread.join();
    }
}

void ThreadPool::enqueue(std::function<void()> task)
{
    {
        std::unique_lock<std::mutex> lock (m_qmutex);
        m_tasks.push(std::move(task));
    }
    m_cv.notify_one();
}

void ThreadPool::run()
{
    while (true) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(m_qmutex);
                m_cv.wait(lock, [this] { return !m_tasks.empty(); });
                task = std::move(m_tasks.front());
                m_tasks.pop();
            }
            task();
        }
}