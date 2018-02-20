#include <unordered_map>
#include <map>

namespace
{

template <typename T>
int get_fib(const int n, T& m)
{
	if (1 == n || 2 == n) {
		return 1;
	}
	int& a = m[n - 1];
	int& b = m[n - 2];
	if (0 == a) {
		a = get_fib(n - 1, m);
	}
	if (0 == b) {
		b = get_fib(n - 2, m);
	}
	return a + b;
}

}

int smart_fib_map(const int n)
{
	std::map<int, int> m;
	return get_fib(n, m);
}

int smart_fib_unordered_map(const int n)
{
	std::unordered_map<int, int> m;
	return get_fib(n, m);
}
