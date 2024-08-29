#include "sorting/sort_algorithm.h"
#include "utility/numbers.h"
#include "sorting/test.h"

int main()
{
    Log::Instance().SetLogLevel(Log::Level::LOG_DEBUG);
    Log::Instance().SetLogFile("log.txt", std::ios::out);

    std::vector<int> vec;
    // Numbers::GenerateSortedNumbers(1000, true, vec);
    Numbers::GetNumbersFromData("1Kints.txt", vec);
    // Numbers::GenerateRandomNumbers(10, 0, 100, vec);
    std::list list(vec.begin(), vec.end());

    // TestSortAlgorithm("Bubble", BubbleSort, vec);
    // TestSortAlgorithm("BubbleWithFlag", BubbleSortWithFlag, vec);
    // TestSortAlgorithm("Selection", SelectionSort, vec);
    // TestSortAlgorithm("Insertion", InsertionSort, vec);
    // TestSortAlgorithm("Shell", ShellSort, vec);
    TestSortAlgorithm("MergeSortTopToBottom", MergeSortTopToBottom, vec);
    TestSortAlgorithm("MergeSortBasedOnList", MergeSortBasedOnList, list);

    return 0;
}
