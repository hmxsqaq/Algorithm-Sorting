#include "sort_base.h"

#include <list>

#include "utility/function_tracker.h"

FunctionTracker swap_tracker("Swap");
FunctionTracker compare_tracker("Compare");
bool track_swap = false;
bool track_compare = false;

void Swap(int &a, int &b) {
    if (track_swap) swap_tracker.FunctionStart();
    std::swap(a, b);
    if (track_swap) swap_tracker.FunctionEnd();
}

bool IsSmaller(const int &a, const int &b) {
    if (track_compare) compare_tracker.FunctionStart();
    const bool result = a < b;
    if (track_compare) compare_tracker.FunctionEnd();
    return result;
}

bool IsGreater(const int &a, const int &b) {
    if (track_compare) compare_tracker.FunctionStart();
    const bool result = a > b;
    if (track_compare) compare_tracker.FunctionEnd();
    return result;
}

bool IsSorted(const std::vector<int> &vec) {
    for (int i = 0; i < vec.size() - 1; i++)
        if (vec[i] > vec[i + 1])
            return false;
    return true;
}

bool IsSorted(const std::list<int> &list) {
    if (list.size() < 2) return true;
    auto it = list.begin();
    auto next_it = std::next(it);
    while (next_it != list.end()) {
        if (*next_it < *it) return false;
        ++it;
        ++next_it;
    }
    return true;
}

void PrintVec(const std::vector<int> &vec) {
    std::ostringstream oss;
    for (const int i : vec)
        oss << " " << i;
    LOG_INFO("[" + oss.str() + " ]");
}

void PrintVec(const std::list<int> &list) {
    std::ostringstream oss;
    for (const int i : list)
        oss << " " << i;
    LOG_INFO("[" + oss.str() + " ]");
}
