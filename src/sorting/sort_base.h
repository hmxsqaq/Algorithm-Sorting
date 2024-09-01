#ifndef SORT_H
#define SORT_H

#include <list>
#include <vector>

void Swap(std::vector<int> &vec, int a, int b);
bool IsSmaller(const int &a, const int &b);
bool IsGreater(const int &a, const int &b);
bool IsEqual(const int &a, const int &b);
bool IsSorted(const std::vector<int> &vec);
bool IsSorted(const std::list<int> &list);
void PrintVec(const std::vector<int> &vec);
void PrintVec(const std::list<int> &list);

#endif //SORT_H
