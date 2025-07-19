#include <iostream>

class Base {
	std::string m_Str;
public:
	Base() : m_Str("") {
		std::cout << "Base Default Constructor" << '\n';
	}
	Base(std::string s) : m_Str(s) {
		std::cout << "Base Param constructor" << '\n';
	}
};

class Derived : public Base {
	using Base::Base;
};
int main() {
	Derived d1;
	Derived d2("Anupam");
}