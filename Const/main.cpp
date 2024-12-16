#include <iostream>

int main() {
	int x = 10;
	const int y = 15;
	int z = 20;

	int* ptr = &x;
	std::cout << *ptr << "\n";
	ptr = &z;
	std::cout << *ptr <<"\n" << ++(*ptr) << "\n";

	//int* ptr = &y; // Error in comiplation
	
	const int* ptr2 = &x; // same as -> int const* ptr2 = &x;
	std::cout << *ptr2 << "\n" ;
	//std::cout << (*ptr2)++ << "\n";  // Error
	ptr2 = &y;
	std::cout << *ptr2 << "\n";

	int* const ptr3 = &x;
	std::cout << *ptr3 << "\n" << ++(*ptr3) << "\n";
	//ptr3 = &z; // Error

	const int* const ptr4 = &y; // same as -> int const* const ptr4 = &y;
	std::cout << *ptr4 << "\n";
	//ptr4 = &x; //Error
	//std::cout << (*ptr4)++ << "\n";  //Error
}