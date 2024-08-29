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

#endif //SORT_ALGORITHM_H
