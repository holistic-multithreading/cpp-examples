sum_ints_lib = libsum_ints.a
main_binary = sum_ints_main.out
benchmark = sum_ints_benchmark.out
cpp_standard = c++17

run_main: $(main_binary)
	./$(main_binary)

$(main_binary): sum_ints_main.cc $(sum_ints_lib)
	$(CXX) sum_ints_main.cc -std=$(cpp_standard) -L. -lsum_ints -pthread -O3 -o $(main_binary)

$(sum_ints_lib): sum_ints.h sum_ints.cc
	$(CXX) -c -O3 -std=$(cpp_standard) sum_ints.cc
	ar rcs $(sum_ints_lib) sum_ints.o

$(benchmark): sum_ints_benchmark.cc $(sum_ints_lib)
	$(CXX) sum_ints_benchmark.cc -std=$(cpp_standard) -lbenchmark -L. -lsum_ints -pthread -O3 -o $(benchmark)

run_benchmark: $(benchmark)
	./$(benchmark) --benchmark_time_unit=ms

clean:
	rm -f *.a *.o *.s *.out
