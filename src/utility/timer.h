#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <utility>
#include "log.h"

class Timer {
public:
    explicit Timer(std::string name = "Timer", const bool auto_log = true)
        : name_(std::move(name)), last_time_point_(Clock::now()), auto_log_(auto_log) { }

    ~Timer() {
        if (!is_stopped_) Stop();
        if (auto_log_) Log();
    }

    void Start() {
        if (is_started_) return;
        last_time_point_ = Clock::now();
        is_started_ = true;
        is_paused_ = false;
        is_stopped_ = false;
    }

    void Pause() {
        if (is_paused_ || is_stopped_) return;
        duration_ += std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() - last_time_point_);
        is_paused_ = true;
    }

    void Resume() {
        if (!is_paused_ || is_stopped_) return;
        last_time_point_ = Clock::now();
        is_paused_ = false;
    }

    void Stop() {
        if (is_stopped_) return;
        Pause();
        is_started_ = false;
        is_paused_ = false;
        is_stopped_ = true;
    }

    void Log() const {
        LOG_INFO("Timer - " + name_ + ": " + std::to_string(duration_.count()) + "us");
    }

    [[nodiscard]] std::string name() const { return name_; }
    [[nodiscard]] long long duration() const { return duration_.count(); }

private:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = Clock::time_point;
    using Duration = std::chrono::microseconds;

    std::string name_;
    TimePoint last_time_point_;
    Duration duration_ = Duration::zero();
    bool is_stopped_ = false;
    bool is_paused_ = false;
    bool is_started_ = false;
    bool auto_log_;
};

#endif //TIMER_H
