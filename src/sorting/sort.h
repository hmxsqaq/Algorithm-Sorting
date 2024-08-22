#ifndef SORT_H
#define SORT_H

#include <sstream>
#include <vector>
#include "utility/function_tracker.h"
#include "utility/log.h"

inline auto swap_tracker = FunctionTracker("Swap");
inline auto compare_tracker = FunctionTracker("Compare");

inline void Swap(int &a, int &b) {
    swap_tracker.FunctionStart();
    std::swap(a, b);
    swap_tracker.FunctionEnd();
}

inline bool IsASmallerThanB(const int &a, const int &b) {
    compare_tracker.FunctionStart();
    const bool result = a < b;
    compare_tracker.FunctionEnd();
    return result;
}

inline bool IsAGreaterThanB(const int &a, const int &b) {
    compare_tracker.FunctionStart();
    const bool result = a > b;
    compare_tracker.FunctionEnd();
    return result;
}

inline bool IsSorted(const std::vector<int> &vec) {
    for (int i = 0; i < vec.size() - 1; i++)
        if (vec[i] > vec[i + 1])
            return false;
    return true;
}

inline void PrintVec(const std::vector<int> &vec) {
    std::ostringstream oss;
    for (const int i : vec)
        oss << " " << i;
    LOG_INFO("[" + oss.str() + " ]");
}

#endif //SORT_H
