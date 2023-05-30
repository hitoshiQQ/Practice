#include "Timer.h"

#define TIME_ACCESS_ENABLE

std::mutex Timer::access_t;

std::chrono::time_point<std::chrono::high_resolution_clock,
    std::chrono::duration<double, std::chrono::seconds::period>> Timer::time_now() {
#ifdef TIME_ACCESS_ENABLE
    Timer::access_t.lock();

#endif
    std::chrono::time_point<std::chrono::high_resolution_clock,
        std::chrono::duration<double, std::chrono::seconds::period>> time_now
        = std::chrono::high_resolution_clock::now();

#ifdef TIME_ACCESS_ENABLE
    Timer::access_t.unlock();

#endif
    return time_now;
}