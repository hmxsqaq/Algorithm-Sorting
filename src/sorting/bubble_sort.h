#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sort.h"
#include "utility/timer.h"

class BubbleSort {
public:
    template <typename T>
    static void Sort(T* array, const size_t size) {
        Timer timer("BubbleSort");
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = 0; j < size - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    Swap(array[j], array[j + 1]);
                }
            }
        }
    }
};

#endif //BUBBLE_SORT_H
