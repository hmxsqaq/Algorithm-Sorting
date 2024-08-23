#ifndef SORT_H
#define SORT_H

#include <vector>

void Swap(int &a, int &b);
bool IsSmaller(const int &a, const int &b);
bool IsGreater(const int &a, const int &b);
bool IsSorted(const std::vector<int> &vec);
void PrintVec(const std::vector<int> &vec);

#endif //SORT_H
