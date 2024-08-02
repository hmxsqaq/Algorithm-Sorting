#include <thread>
#include "utility/log.h"
#include "utility/timer.h"

int main()
{
    Log::Instance().SetLogLevel(Log::Level::LOG_DEBUG);
    Log::Instance().SetLogFile("log.txt", std::ios::out);

    Timer timer("Main");
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    timer.Stop();

    return 0;
}
