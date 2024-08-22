#include <thread>

#include "sorting/bubble_sort.h"
#include "sorting/numbers.h"
#include "sorting/test.h"

int main()
{
    Log::Instance().SetLogLevel(Log::Level::LOG_DEBUG);
    Log::Instance().SetLogFile("log.txt", std::ios::out);

    std::vector<int> nums;

    Numbers::GetNumbersFromData("1Kints.txt", nums);
    TestSortAlgorithm("BubbleSort", BubbleSort::Normal, nums);
    TestSortAlgorithm("BubbleSortWithFlag", BubbleSort::WithFlag, nums);

    Numbers::GenerateRandomNumbers(10, 0, 100, nums);
    TestSortAlgorithm("BubbleSort2", BubbleSort::Normal, nums);

    return 0;
}
