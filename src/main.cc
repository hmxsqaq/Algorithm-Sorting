#include "sorting/sort_algorithm.h"
#include "utility/numbers.h"
#include "sorting/test.h"

int main()
{
    Log::Instance().SetLogLevel(Log::Level::LOG_DEBUG);
    Log::Instance().SetLogFile("log.txt", std::ios::out);

    std::vector<int> nums;
    // Numbers::GenerateSortedNumbers(1000, true, nums);
    Numbers::GetNumbersFromData("1Kints.txt", nums);
    // Numbers::GenerateRandomNumbers(10, 0, 100, nums);

    // TestSortAlgorithm("Bubble", BubbleSort, nums);
    // TestSortAlgorithm("BubbleWithFlag", BubbleSortWithFlag, nums);
    // TestSortAlgorithm("Selection", SelectionSort, nums);
    // TestSortAlgorithm("Insertion", InsertionSort, nums);
    // TestSortAlgorithm("Shell", ShellSort, nums);
    TestSortAlgorithm("Merge", MergeSortBottomToTop, nums);
    return 0;
}
