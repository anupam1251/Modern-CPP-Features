#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Qualifier - that modifies behaviour/properties of a variable/object
 
// 1. const     - makes a variable read only
// 2. volatile  - prevent compiler optimization on a variable that can change unexpectedly
// 3. mutable   - allows a class member to be modified even if the containing object is const

/*
volatile int currTemp = 25;

void increasingTemparatue() {

	while (++currTemp < 45) {

		this_thread::sleep_for(chrono::milliseconds(100));
	}

}

int main() {

	cout << "Morning Temparature : " << currTemp << '\n';
	thread t(increasingTemparatue);


	while (currTemp < 45) {

	}

	t.join();
	cout << "Afternoon Temparature : " << currTemp << '\n';
	cout << "WARNING! Excessive Heat - Stay at Home" << '\n';


	return  0;

} 

*/


class Entity {
	string m_Name;
	mutable int debugCount = 0;
public:

	const string getName() const{
		++debugCount;
		return m_Name;
	}

};

int main() {

	const Entity e;
	e.getName();

	int x = 10;
	
	auto f = [=]() mutable{
		x++;
	};

	f();
	cout << x << '\n'; // value of x is not changing
}