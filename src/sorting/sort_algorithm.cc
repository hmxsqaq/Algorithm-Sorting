#include "sort_algorithm.h"

/* ---------------BubbleSort--------------- */
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


/* ---------------SelectionSort--------------- */
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


/* ---------------InsertionSort--------------- */
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

void InsertionSort(std::vector<int> &vec, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int num = vec[i], j = i;
        while (j > left && IsSmaller(num, vec[j - 1])) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = num;
    }
}


/* ---------------ShellSort--------------- */
void ShellSort(std::vector<int> &vec) {
    const int size = static_cast<int>(vec.size());
    int h = size / 3;
    while (h >= 1) {
        for (int i = h; i < size; ++i) {
            int num = vec[i], j = i;
            while (j >= h && IsSmaller(num, vec[j - h])) {
                vec[j] = vec[j - h];
                j -= h;
            }
            vec[j] = num;
        }
        h /= 3;
    }
}


/* ---------------MergeSortTopToBottom--------------- */
void Merge(std::vector<int> &vec, const int left, const int mid, const int right) {
    const int length = right - left + 1;
    std::vector<int> temp(length);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (IsSmaller(vec[i], vec[j]))  temp[k++] = vec[i++];
        else                            temp[k++] = vec[j++];
    }
    while (i <= mid)    temp[k++] = vec[i++];
    while (j <= right)  temp[k++] = vec[j++];
    for (k = 0; k < length; ++k) {
        vec[k + left] = temp[k];
    }
}

void MergeSortTopToBottom(std::vector<int> &vec, const int left, const int right) {
    if (left >= right) return;
    const int mid = (right + left) / 2;
    MergeSortTopToBottom(vec, left, mid);
    MergeSortTopToBottom(vec, mid + 1, right);
    Merge(vec, left, mid, right);
}

void MergeSortTopToBottom(std::vector<int> &vec) {
    const int size = static_cast<int>(vec.size());
    MergeSortTopToBottom(vec, 0, size - 1);
}

/* ---------------MergeSortBottomToTop--------------- */
void MergeSortBottomToTop(std::vector<int> &vec) {
    const int size = static_cast<int>(vec.size());
    for (int length = 1; length < size; length *= 2) {
        for (int left = 0; left < size - length; left += 2 * length) {
            const int mid = left + length - 1;
            const int right = std::min(left + 2 * length - 1, size - 1);
            Merge(vec, left, mid, right);
        }
    }
}

/* ---------------MergeSortBasedOnList--------------- */
std::list<int> MergeSortBasedOnList(std::list<int> &list) {
    if (list.size() <= 1) return list;

    const int size = static_cast<int>(list.size());
    auto mid = std::next(list.begin(), size / 2);
    std::list<int> left;
    left.splice(left.begin(), list, list.begin(), mid);

    left = MergeSortBasedOnList(left);
    std::list<int> right = MergeSortBasedOnList(list);

    left.merge(right);
    return left;
}

/* ---------------MergeSortBasedOnList--------------- */
void MergeOptimized(const std::vector<int> &source, std::vector<int> &destination, const int left, const int mid, const int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (IsSmaller(source[i], source[j]))    destination[k++] = source[i++];
        else                                    destination[k++] = source[j++];
    }
    while (i <= mid)    destination[k++] = source[i++];
    while (j <= right)  destination[k++] = source[j++];
}

void MergeSortOptimized(std::vector<int> &source, std::vector<int> &destination, const int left, const int right) {
    static int kCUTOFF = 7;
    if (right - left <= kCUTOFF) {  // apply insertion sort for small subarrays
        InsertionSort(destination, left, right);
        return;
    }
    const int mid = (right + left) / 2;
    // *self-merge: avoid creating temp array when merging
    MergeSortOptimized(destination, source, left, mid);
    MergeSortOptimized(destination, source, mid + 1, right);
    // test if array is sorted before merge
    if (IsSmaller(source[mid], source[mid + 1])) {
        std::copy(source.begin() + left, source.begin() + right + 1, destination.begin() + left);
        return;
    }
    MergeOptimized(source, destination, left, mid, right);
}

void MergeSortOptimized(std::vector<int> &vec) {
    const int size = static_cast<int>(vec.size());
    std::vector aux_vec(vec);
    MergeSortOptimized(aux_vec, vec, 0, size - 1);
}
