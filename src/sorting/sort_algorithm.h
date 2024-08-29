#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

#include <list>
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
#endif //SORT_ALGORITHM_H
