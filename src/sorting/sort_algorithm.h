#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

#include <list>
#include <iostream>
#include "sort_base.h"

void BubbleSort(std::vector<int> &vec);
void BubbleSortWithFlag(std::vector<int> &vec);

void SelectionSort(std::vector<int> &vec);

void InsertionSort(std::vector<int> &vec);

void ShellSort(std::vector<int> &vec);

void MergeSortTopToBottom(std::vector<int> &vec);
void MergeSortBottomToTop(std::vector<int> &vec);
std::list<int> MergeSortBasedOnList(std::list<int> &list);
// 1. apply insertion sort for small subarrays
// 2. test if array is sorted before merge
// 3. *self-merge: avoid creating temp array when merging
void MergeSortOptimized(std::vector<int> &vec);

void QuickSort(std::vector<int> &vec);
void QuickSort3Sample(std::vector<int> &vec);
void QuickSort3Way(std::vector<int> &vec);

class MaxPriorityQueue {
public:
    MaxPriorityQueue() { pq_.push_back(0); }
    void Insert(int key);
    int ExtractMax();
    [[nodiscard]] int GetMax() const;
    [[nodiscard]] bool IsEmpty() const { return pq_.size() <= 1; }
    [[nodiscard]] size_t GetSize() const { return pq_.size() - 1; }
private:
    std::vector<int> pq_;
    void Swim(int i);
    void Sink(int i);
};
void HeapSortBrute(std::vector<int> &vec);
void SinkFrom0(std::vector<int> &vec, int root, int end);
void SinkFrom1(std::vector<int> &vec, int root, int end);
void HeapSortInPlace(std::vector<int> &vec);

#endif //SORT_ALGORITHM_H
