#include <Windows.h>
#include <iostream>
#include <thread>


/*
typedef unsigned long long int ull;

ull oddSum = 0;
ull evenSum = 0;

void findOdd(ull start, ull end) {
	for (int i = start; i <= end; i++) {
		if ((i & 1) == 1)
			oddSum += i;
	}
}

void findEven(ull start, ull end) {
	for (int i = start; i <= end; i++) {
		if ((i & 1) == 0)
			evenSum += i;
	}
}

int main() {
	
	ull start = 0, end = 1900000000;
	DWORD startTime = GetTickCount();

	std::thread t1(findOdd,start,end);
	std::thread t2(findEven,start,end);

	t1.join();
	t2.join();

	//findOdd(start, end);
	//findEven(start, end);

	DWORD endTime = GetTickCount();
	std::cout << "Even sum : " << evenSum << '\n';
	std::cout << "Odd sum  : " << oddSum << '\n';
	std::cout << "Elapsed Time : " << endTime - startTime << '\n';  
	
} */



//There are 5 different ways to create thread in c++ using caller object
//1. Function pointer
//2. Lambda function
//3. Functor
//4. Non static memeber function 
//5. static member function


/*
//1. Function Pointer
void fun(int x) {
	while (x-- > 0)
		std::cout << x << " ";
}

int main() {
	std::thread t(fun,5);
	t.join();
}  */


/*
//2. Lambda Funtion
auto fun = [](int x) {
	while (x-- > 0)
		std::cout << x << " ";
};

int main() {
	std::thread t(fun, 10);
	t.join();
}  */


/*
//3. Functor
class Base {
public:
	void operator()(int x) {
		while (x-- > 0)
			std::cout << x << " ";
	}
};
int main() {
	std::thread t(Base(), 10);
	t.join();
} */



/*
//4.Non Static member function
class Base {
public:
	void fun(int x) {
		while (x-- > 0)
			std::cout << x << " ";
	}
};

int main() {
	Base b;
	std::thread t(&Base::fun, &b, 10);
	t.join();
}  */



/*
//5. Static member function
class Base {
public:
	static void fun(int x) {
		while (x-- > 0)
			std::cout << x << " ";
	}
};
int main() {
	std::thread t(&Base::fun, 10);
	t.join();
}  */