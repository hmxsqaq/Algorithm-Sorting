#ifndef TTEST_H
#define TTEST_H

#include <functional>
#include <string>

void TestSortAlgorithm(const std::string& algorithm_name, const std::function<void(std::vector<int>&)> &sort_algorithm, const std::vector<int> &vec, bool show_vec = false);

#endif //TTEST_H
