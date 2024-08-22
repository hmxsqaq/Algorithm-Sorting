#ifndef TTEST_H
#define TTEST_H

#include <functional>
#include "sort.h"
#include "utility/log.h"

inline void TestSortAlgorithm(const std::string& algorithm_name, const std::function<void(std::vector<int>&)> &sort_algorithm, std::vector<int> &vec) {
    std::vector<int> copyed_vec = vec;
    swap_tracker.Reset();
    compare_tracker.Reset();

    Timer timer(algorithm_name, false);
    sort_algorithm(copyed_vec);
    timer.Stop();

    swap_tracker.Log();
    compare_tracker.Log();
    timer.Log();

    if (IsSorted(copyed_vec)) {
        LOG_INFO("Test - PASSED\n");
    } else {
        LOG_ERROR("Test - FAILED\n");
    }
}

#endif //TTEST_H
