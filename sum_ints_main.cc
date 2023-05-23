#include <chrono>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <thread>

#include "sum_ints.h"

using holistic_multithreading::MultithreadedSum;
using holistic_multithreading::SingleThreadSum;

int main(int argc, char *argv[]) {
  std::cout << "Number of CPUs as counted by C++ standard library: "
            << std::thread::hardware_concurrency() << std::endl;
  std::cout << "Single-thread sum is: " << SingleThreadSum(1, 1'000'000'000)
            << std::endl;
  auto start = std::chrono::high_resolution_clock::now();
  std::cout << "Multithreaded sum is: "
            << MultithreadedSum(1, 1'000'000'000, 10) << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::nanoseconds duration_nanos = end - start;
  std::chrono::microseconds duration_micros =
      std::chrono::duration_cast<std::chrono::microseconds>(duration_nanos);
  std::chrono::milliseconds duration_millis =
      std::chrono::duration_cast<std::chrono::milliseconds>(duration_nanos);
  std::cout << "Multithreaded call took " << duration_nanos.count() << " ns"
            << " (" << duration_micros.count() << " us or "
            << duration_millis.count() << " ms)" << std::endl;
  std::cout << "Another way to caclulate call duration in ns: "
            << end.time_since_epoch().count() - start.time_since_epoch().count()
            << std::endl;
  return EXIT_SUCCESS;
}
