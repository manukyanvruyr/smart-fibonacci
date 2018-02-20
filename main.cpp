#include <iostream>
#include <chrono>
#include <assert.h>

#include "fibonacci.hpp"

void test()
{
	std::chrono::high_resolution_clock clk;

	auto start = clk.now();
	for (std::size_t f = 10000; f < 1000000000; f *= 2) {
		int n1 = smart_fib_map(10000);
		auto end = clk.now();
		std::chrono::duration<double> time1 = end - start;

		start = clk.now();
		int n2 = smart_fib_map(10000);
		end = clk.now();
		std::chrono::duration<double> time2 = end - start;

		assert(n1 == n2);
		std::cout << "fib(" << f << ") using map: " << time1.count() << std::endl;
		std::cout << "fib(" << f << ") using unordered map: " << time2.count() << std::endl << std::endl;
	}
}

int main()
{
	test();
	return 0;
}
