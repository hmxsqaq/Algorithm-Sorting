#include "sorting/bubble_sort.h"
#include "utility/log.h"
#include "utility/timer.h"

int main()
{
    Log::Instance().SetLogLevel(Log::Level::LOG_DEBUG);
    Log::Instance().SetLogFile("log.txt", std::ios::out);

    Test::Sorting(BubbleSort::Sort<int>, "32Kints.txt");
    Test::Sorting(BubbleSort::Sort<int>, 32000, -1000, 1000);

    return 0;
}
