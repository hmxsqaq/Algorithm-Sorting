#include "test.h"

#include "sort_base.h"
#include "utility/function_tracker.h"

extern FunctionTracker swap_tracker;
extern FunctionTracker compare_tracker;

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
    swap_tracker.Log();
    compare_tracker.Log();
    timer.Log();

    if (IsSorted(copyed_vec)) {
        LOG_INFO("Test - PASSED\n");
    } else {
        LOG_ERROR("Test - FAILED\n");
    }
}
