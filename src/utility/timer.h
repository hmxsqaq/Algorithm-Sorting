#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <utility>
#include "log.h"

class Timer {
public:
    explicit Timer(std::string name = "Timer") : name_(std::move(name)), start_time_point_(Clock::now()) { }

    ~Timer() {
        if (!is_stopped_) Stop();
    }

    void Stop() {
        if (is_stopped_) {
            LOG_WARNING("Timer already stopped");
            return;
        }
        const TimePoint end_time_point = Clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time_point - start_time_point_);
        LOG_INFO("Timer - " + name_ + ": " + std::to_string(duration.count()) + "ms");
        is_stopped_ = true;
    }

private:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = Clock::time_point;

    std::string name_;
    TimePoint start_time_point_;
    bool is_stopped_ = false;
};

#endif //TIMER_H
