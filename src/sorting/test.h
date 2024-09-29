#ifndef TTEST_H
#define TTEST_H

#include <functional>
#include <list>
#include <string>

void TestSortAlgorithm(const std::string &algorithm_name, const std::function<void(std::vector<int> &)> &sort_algorithm,
                       const std::vector<int> &vec, bool show_vec = false, bool reversed = false);
void TestSortAlgorithm(const std::string& algorithm_name, const std::function<std::list<int>(std::list<int>&)> &sort_algorithm, const std::
                       list<int> &list, bool show_vec = false);

#endif //TTEST_H
