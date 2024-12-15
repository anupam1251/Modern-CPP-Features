#include <iostream>
// expression is evaluated at compile time 

constexpr int add(int a, int b) {
	return a + b;
}

int main() {
	constexpr int i = add(3 , 4);
}