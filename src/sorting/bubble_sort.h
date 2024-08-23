#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <sorting/sort.h>

inline void BubbleSort(std::vector<int>& vec) {
    for (size_t i = vec.size() - 1; i > 0; --i)
        for (size_t j = 0; j < i; j++)
            if (IsGreater(vec[j], vec[j + 1]))
                Swap(vec[j], vec[j + 1]);
}

inline void BubbleSortWithFlag(std::vector<int>& vec) {
    for (size_t i = vec.size() - 1; i > 0; --i) {
        bool flag = false;
        for (size_t j = 0; j < i; j++)
            if (IsGreater(vec[j], vec[j + 1])) {
                Swap(vec[j], vec[j + 1]);
                flag = true;
            }
        if (!flag) break;
    }
}

#endif //BUBBLE_SORT_H
