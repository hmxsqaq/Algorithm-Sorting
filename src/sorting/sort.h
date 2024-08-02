#ifndef SORT_H
#define SORT_H
#include <sstream>

#include "utility/log.h"

template <typename T>
bool IsSorted(const T *array, const int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Show(const T *array, const int size) {
    std::ostringstream oss;
    for (int i = 0; i < size; i++)
        oss << " " << array[i];
    LOG_INFO("[" + oss.str() + "]");
}

#endif //SORT_H
