#ifndef TTEST_H
#define TTEST_H

#include <functional>
#include "sort.h"
#include "utility/log.h"

inline void TestSortAlgorithm(const std::string& algorithm_name, const std::function<void(std::vector<int>&)> &sort_algorithm, std::vector<int> &vec) {
    Timer timer(algorithm_name, false);
    sort_algorithm(vec);
    timer.Stop();
    swap_tracker.Log();
    compare_tracker.Log();
    timer.Log();
    if (IsSorted(vec)) {
        LOG_INFO("Test - " + algorithm_name + " passed\n");
    } else {
        LOG_ERROR("Test - " + algorithm_name + " failed\n");
    }
}

#endif //TTEST_H
