#ifndef FUNCTION_TRACKER_H
#define FUNCTION_TRACKER_H

#include "timer.h"

class FunctionTracker {
public:
    explicit FunctionTracker(std::string name) : timer_(std::move(name), false) { }

    void FunctionStart() {
        timer_.Resume();
    }

    void FunctionEnd() {
        timer_.Pause();
        count_++;
    }

    void Log() const {
        LOG_INFO("Function - " + timer_.name() + "() ran " + std::to_string(count_) + " times, taking " + std::to_string(timer_.duration().count()) + "ms");
    }

private:
    Timer timer_;
    size_t count_ = 0;
};

#endif //FUNCTION_TRACKER_H
