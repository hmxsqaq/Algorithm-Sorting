#ifndef SORT_H
#define SORT_H

#include <sstream>
#include <vector>
#include "utility/log.h"

template <typename T>
static bool IsSorted(const std::vector<T> &vec) {
    for (int i = 0; i < vec.size() - 1; i++)
        if (vec[i] > vec[i + 1])
            return false;
    return true;
}

template <typename T>
static void PrintVec(const std::vector<T> &vec) {
    std::ostringstream oss;
    for (int i = 0; i < vec.size(); i++)
        oss << " " << vec[i];
    LOG_INFO("[" + oss.str() + " ]");
}

#endif //SORT_H
