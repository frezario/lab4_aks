//
// Created by Naz on 3/8/2023.
//
#include <mutex>
#include <condition_variable>
#include <deque>

#ifndef TEMPLATE_THREAD_SAFE_QUEUE_H
#define TEMPLATE_THREAD_SAFE_QUEUE_H

template<class T>
class thread_safe_queue {
    std::deque<T> queue;
    mutable std::mutex data_mutex;
    std::condition_variable data_cond_var;
public:
    thread_safe_queue() = default;

    ~thread_safe_queue() = default;

    thread_safe_queue(const thread_safe_queue &) = delete;

    thread_safe_queue &operator=(const thread_safe_queue &) = delete;

    [[nodiscard]] size_t get_size() const {
        std::unique_lock<std::mutex> lg{data_mutex};
        return queue.size();
    }

    void push(const T &val) {
        {
            std::lock_guard<std::mutex> lg{data_mutex};
            queue.push_back(val);
        }
        data_cond_var.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lck{data_mutex};
        data_cond_var.wait(lck, [this] {return queue.empty();});
        auto res = queue.front();
        queue.pop_front();
        return res;
    }

};

#endif //TEMPLATE_THREAD_SAFE_QUEUE_H
