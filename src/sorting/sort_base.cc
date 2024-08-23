#include "sort_base.h"

#include "utility/function_tracker.h"

FunctionTracker swap_tracker("Swap");
FunctionTracker compare_tracker("Compare");

void Swap(int &a, int &b) {
    swap_tracker.FunctionStart();
    std::swap(a, b);
    swap_tracker.FunctionEnd();
}

bool IsSmaller(const int &a, const int &b) {
    compare_tracker.FunctionStart();
    const bool result = a < b;
    compare_tracker.FunctionEnd();
    return result;
}

bool IsGreater(const int &a, const int &b) {
    compare_tracker.FunctionStart();
    const bool result = a > b;
    compare_tracker.FunctionEnd();
    return result;
}

bool IsSorted(const std::vector<int> &vec) {
    for (int i = 0; i < vec.size() - 1; i++)
        if (vec[i] > vec[i + 1])
            return false;
    return true;
}

void PrintVec(const std::vector<int> &vec) {
    std::ostringstream oss;
    for (const int i : vec)
        oss << " " << i;
    LOG_INFO("[" + oss.str() + " ]");
}
