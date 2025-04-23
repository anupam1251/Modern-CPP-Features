// Source - Rupesh Yadav , YouTube - CppNuts


#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


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

/*
void run(int x) {
	for(int i = 0 ; i < 100 ; i++)
		std::cout <<i<<" Anupam" << '\n';
}
int main() {

	std::thread t1(run, 100);
	while (true) {

	}
	
	t1.join();
	return 0;

} */

/*
void run() {
	int i = 0;
	while (true) {
		std::cout << i++ << " Anupam" << '\n';
	}
}
int main() {

	std::thread t1(run);
	t1.join();

	std::cout << "main thread" << '\n';
	return 0;
} */


//Introduction to mutex


std::mutex mtx;
int counter = 0;

void increment() {
	for (int i = 0; i < 100000; i++) {
		mtx.lock();
		counter++;
		mtx.unlock();
	}
}


void calculatePartailSum(int *arr, int size, int start, int end, int& sum) {
	for (int i = start; i < end; i++) {
		sum += arr[i];
	}
}

int main() {
	/*std::thread t1(increment);
	std::thread t2(increment);

	t1.join();
	t2.join();
	std::cout << "Counter : " << counter << '\n';

	*/

	int arr[10]{ 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int mid = size / 2;
	int sum1 = 0, sum2 = 0;

	std::thread t1(calculatePartailSum, arr, size, 0, mid, std::ref(sum1));
	std::thread t2(calculatePartailSum, arr, size, mid, size, std::ref(sum2));

	t1.join();
	t2.join();

	std::cout << "Sum of Array : " << sum1 + sum2 << '\n';

	return 0;
} 