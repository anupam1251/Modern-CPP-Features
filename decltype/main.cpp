// use of decltype in c++ ? -> it check the type of expression
#include <iostream>

/*
template<typename T1, typename T2>
T1 add(T1 a, T2 b) {
	return a + b;
}
*/

template<typename T1, typename T2>
auto add(T1 a, T2 b) ->decltype(a+b) {
	return a + b;
}



int main() {
	std::cout << add(1, 1.8) << '\n';
	std::cout << add(1.8, 1) << '\n';

	return 0;
}