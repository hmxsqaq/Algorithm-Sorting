#include "sort_algorithm.h"

void BubbleSort(std::vector<int> &vec) {
    const int size = static_cast<int>(vec.size());
    for (int i = size - 1; i > 0; --i)
        for (int j = 0; j < i; j++)
            if (IsGreater(vec[j], vec[j + 1]))
                Swap(vec[j], vec[j + 1]);
}

void BubbleSortWithFlag(std::vector<int> &vec) {
    const int size = static_cast<int>(vec.size());
    for (int i = size - 1; i > 0; --i) {
        bool flag = false;
        for (int j = 0; j < i; j++)
            if (IsGreater(vec[j], vec[j + 1])) {
                Swap(vec[j], vec[j + 1]);
                flag = true;
            }
        if (!flag) break;
    }
}

void SelectionSort(std::vector<int> &vec) {
    const int size = static_cast<int>(vec.size());
    for (int i = 0; i < size; i++) {
        int min_index = i;
        for (int j = i + 1; j < vec.size(); j++)
            if (IsSmaller(vec[j], vec[min_index]))
                min_index = j;
        if (min_index != i)
            Swap(vec[i], vec[min_index]);
    }
}

void InsertionSort(std::vector<int> &vec) {
    const int size = static_cast<int>(vec.size());
    for (int i = 1; i < size; i++) {
        int num = vec[i], j = i;
        while (j > 0 && IsSmaller(num, vec[j - 1])) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = num;
    }
}
