sum_ints_lib = libsum_ints.a
benchmark = sum_ints_benchmark
cpp_standard = c++17

run_main: sum_ints_main
	./sum_ints_main

sum_ints_main: sum_ints_main.cc $(sum_ints_lib)
	$(CXX) sum_ints_main.cc -std=$(cpp_standard) -L. -lsum_ints -lpthread -O3 -o sum_ints_main

$(sum_ints_lib): sum_ints.h sum_ints.cc
	$(CXX) -c -O3 -std=$(cpp_standard) sum_ints.cc
	ar rcs $(sum_ints_lib) sum_ints.o

$(benchmark): sum_ints_benchmark.cc $(sum_ints_lib)
	$(CXX) sum_ints_benchmark.cc -std=$(cpp_standard) -lbenchmark -L. -lsum_ints -lpthread -O3 -o $(benchmark)

run_benchmark: $(benchmark)
	./sum_ints_benchmark --benchmark_time_unit=ms

static: sum_ints_main.cc $(sum_ints_lib)
	$(CXX) sum_ints_main.cc -std=$(cpp_standard) -L. -lsum_ints -lpthread -O3 -o sum_ints_main_static

asm: sum_ints.cc
	$(CXX) sum_ints.cc -std=$(cpp_standard) -S

clean:
	rm -f *.a *.o *.s sum_ints_main sum_ints_main_static sum_ints_benchmark
