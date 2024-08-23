#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <sorting/sort.h>


inline void SelectionSort(std::vector<int> &vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < vec.size(); j++)
            if (IsSmaller(vec[j], vec[min_index]))
                min_index = j;
        if (min_index != i)
            Swap(vec[i], vec[min_index]);
    }
}


#endif //SELECTION_SORT_H
