#include <iostream>

template<class T>
T square(T input) {
	return input * input;
}

auto square2(auto input) {
	return input * input;
}

template<typename T1, typename T2>
void foo(T1 input1, T2 input2) {
	std::cout << typeid(input1).name() << std::endl;
	std::cout << typeid(input2).name() << std::endl;
}

template<typename T>
bool equal(T a, T b) {
	return (a == b);
}

template<>
bool equal<float>(float a, float b) {
	std::cout << "equal<float>" << std::endl;
	return fabs(a-b) < 0.0001f;
}

int main() {
	std::cout << square(5) << std::endl;
	std::cout << square(5.5) << std::endl;
	std::cout << square(6.5f) << std::endl;
	std::cout << square<double>(10.5) << std::endl;

	std::cout << square2(7) << std::endl;

	foo<int, float>(10, 3.5);

	std::cout << equal<int>(2, 2) << std::endl;
	std::cout << equal<int>(2, 3) << std::endl;

	std::cout << equal<float>(1.0f- 0.999999f, 0.000001f) << std::endl;
	std::cout << equal<float>(2.5f,3.5f) << std::endl;


	return 0;
}