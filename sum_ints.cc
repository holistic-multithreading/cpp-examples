#include "sum_ints.h"

#include <cstdint>
#include <functional>
#include <numeric>
#include <thread>
#include <vector>

namespace holistic_multithreading {
namespace {

void SumValues(int64_t from, int64_t to, int64_t &result) {
  for (int64_t i = from; i <= to; i++) {
    result += i % 10;
  }
}

} // namespace

int64_t MultithreadedSum(int64_t from, int64_t to, int64_t thread_count) {
  int64_t batch_size = (to - from + 1) / thread_count;
  std::vector<std::thread> threads;
  threads.reserve(thread_count);
  std::vector<int64_t> results;
  results.reserve(thread_count);
  int64_t start = from;
  for (int64_t i = 0; i < thread_count; i++) {
    int64_t end = (i < thread_count - 1) ? start + batch_size - 1 : to;
    results.push_back(0);
    threads.push_back(
        std::thread(SumValues, start, end, std::ref(results.back())));
    start = end + 1;
  }
  for (auto &t : threads) {
    t.join();
  }
  return std::accumulate(results.begin(), results.end(),
                         static_cast<int64_t>(0));
}

int64_t SingleThreadSum(int64_t from, int64_t to) {
  int64_t result = 0;
  SumValues(from, to, result);
  return result;
}

} // namespace holistic_multithreading
