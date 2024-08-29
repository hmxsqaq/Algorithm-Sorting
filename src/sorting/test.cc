#include "test.h"

#include "sort_base.h"
#include "utility/function_tracker.h"

extern FunctionTracker swap_tracker;
extern FunctionTracker compare_tracker;
extern bool track_swap;
extern bool track_compare;

void TestSortAlgorithm(const std::string &algorithm_name,
                       const std::function<void(std::vector<int> &)> &sort_algorithm,
                       const std::vector<int> &vec,
                       const bool show_vec) {
    std::vector<int> copyed_vec = vec;
    swap_tracker.Reset();
    compare_tracker.Reset();
    if (show_vec) PrintVec(copyed_vec);

    Timer timer(algorithm_name, false);
    sort_algorithm(copyed_vec);
    timer.Stop();

    if (show_vec) PrintVec(copyed_vec);
    if (track_swap) swap_tracker.Log();
    if (track_compare) compare_tracker.Log();
    timer.Log();

    if (IsSorted(copyed_vec)) {
        LOG_INFO("Test - PASSED\n");
    } else {
        LOG_ERROR("Test - FAILED\n");
    }
}

void TestSortAlgorithm(const std::string &algorithm_name,
                       const std::function<std::list<int>(std::list<int> &)> &sort_algorithm,
                       const std::list<int> &list,
                       const bool show_vec) {
    std::list copyed_vec(list.begin(), list.end());
    if (show_vec) PrintVec(copyed_vec);

    Timer timer(algorithm_name, false);
    copyed_vec = sort_algorithm(copyed_vec);
    timer.Stop();

    if (show_vec) PrintVec(copyed_vec);
    timer.Log();

    if (IsSorted(copyed_vec)) {
        LOG_INFO("Test - PASSED\n");
    } else {
        LOG_ERROR("Test - FAILED\n");
    }
}
