#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

#include "sort_base.h"

void BubbleSort(std::vector<int> &vec);
void BubbleSortWithFlag(std::vector<int> &vec);

void SelectionSort(std::vector<int> &vec);

void InsertionSort(std::vector<int> &vec);

void ShellSort(std::vector<int> &vec);

void MergeSort(std::vector<int> &vec);

#endif //SORT_ALGORITHM_H
