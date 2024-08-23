#include "sorting/bubble_sort.h"
#include "utility/numbers.h"
#include "sorting/selection_sort.h"
#include "sorting/test.h"

int main()
{
    Log::Instance().SetLogLevel(Log::Level::LOG_DEBUG);
    Log::Instance().SetLogFile("log.txt", std::ios::out);

    std::vector<int> nums;
    // Numbers::GenerateSortedNumbers(1000, true, nums);
    Numbers::GetNumbersFromData("1Kints.txt", nums);

    TestSortAlgorithm("Bubble", BubbleSort, nums);
    // TestSortAlgorithm("BubbleWithFlag", BubbleSortWithFlag, nums);
    TestSortAlgorithm("Selection", SelectionSort, nums);

    return 0;
}
