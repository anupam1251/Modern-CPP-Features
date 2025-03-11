// Source - Rupesh Yadav , YouTube - CppNuts


#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>


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


//Use of join(), detach() and joinable() in thread c++

//Join Notes

//1. Once a thread is started we wait for this thread to finish by calling join() function on thread object
//2. double join will result into program termination
//3. if needed we should check thread is joinable before join() (using joinable() function)
/*
void run(int x) {
	while (x-- > 0)
		std::cout << "Anupam" << '\n';
	std::this_thread::sleep_for(std::chrono::seconds(3));
}
int main() {
	std::cout << "main()" << '\n';
	std::thread t(run, 10);
	t.join();
	if(t.joinable())
		t.join();
	std::cout << "main() after" << '\n';
	return 0;
}    */

//Detach Notes

//1. This is used to detach newly created thread from parent thread
//2. Always check before detaching a thread that it is joinable otherwise we may end up
//   double detaching & result will be program termination
//3. If we have detached the thread and main() is returning then the detached thread execution is suspended.

/*
void run(int x) {
	while (x-- > 0) {
		std::cout << "Anupam" << '\n';
	}
	std::cout << "thread finished" << '\n';
}
int main() {
	std::cout << "main()" << '\n';
	std::thread t(run, 10);
	t.detach();
	std::cout << "main() after" << '\n';
	std::this_thread::sleep_for(std::chrono::seconds(2));
	return 0;
} */