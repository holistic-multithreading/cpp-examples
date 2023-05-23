#ifndef HOLISTIC_MULTITHREADING_CODE_SAMPLES_THREAD_SUM_SUM_INTS_H_
#define HOLISTIC_MULTITHREADING_CODE_SAMPLES_THREAD_SUM_SUM_INTS_H_

#include <cstdint>

namespace holistic_multithreading {

int64_t MultithreadedSum(int64_t from, int64_t to, int64_t thread_count);

int64_t SingleThreadSum(int64_t from, int64_t to);

} // namespace holistic_multithreading

#endif // HOLISTIC_MULTITHREADING_CODE_SAMPLES_THREAD_SUM_SUM_INTS_H_
