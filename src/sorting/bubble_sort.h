#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "utility/timer.h"

class BubbleSort {
public:
    template <typename T>
    static void Normal(std::vector<T>& vec) {
        Timer timer("BubbleSort");
        for (size_t i = vec.size() - 1; i > 0; --i)
            for (size_t j = 0; j < i; j++)
                if (vec[j] > vec[j + 1])
                    std::swap(vec[j], vec[j + 1]);
    }
};

#endif //BUBBLE_SORT_H
