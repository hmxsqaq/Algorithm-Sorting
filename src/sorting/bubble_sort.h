#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <sorting/sort.h>

class BubbleSort {
public:
    static void Normal(std::vector<int>& vec) {
        for (size_t i = vec.size() - 1; i > 0; --i)
            for (size_t j = 0; j < i; j++)
                if (IsAGreaterThanB(vec[j], vec[j + 1]))
                    Swap(vec[j], vec[j + 1]);
    }
};

#endif //BUBBLE_SORT_H
