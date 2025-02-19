#include <iostream>

template<typename T>
class uniquePtr {
	T* m_res;

public:
	uniquePtr(T* ptr = nullptr) : m_res(ptr) {
		std::cout << "Constructor invoked" << '\n';
	}

	uniquePtr(const uniquePtr& ptr) = delete;

	uniquePtr& operator= (const uniquePtr& ptr) = delete;

	uniquePtr(uniquePtr&& ptr) : m_res(ptr.m_res) {
		ptr.m_res = nullptr;
		std::cout << "Move constructor invoked" << '\n';
	}

	uniquePtr& operator= (uniquePtr&& ptr) {
		if (this != &ptr) {
			delete m_res;
			m_res = ptr.m_res;
			ptr.m_res = nullptr;
		}
		return *this;
		std::cout << "Move assignment operator called" << '\n';
	}

	T* operator->() {
		return m_res;
	}

	T& operator*() {
		return *m_res;
	}

	T* get() {
		return m_res;
	}

	void reset(T* ptr = nullptr) {
		if (m_res)
			delete m_res;
		m_res = ptr;
	}
	
	~uniquePtr() {
		delete m_res;
		m_res = nullptr;
		std::cout << "Destructor invoked" << '\n';
	}
	void fun(){}
};

int main() {

	uniquePtr<int> ptr1;
	uniquePtr<int> ptr2(new int(5));

	//uniquePtr<int> ptr3(ptr1); //should compilation error
	//uniquePtr<int> ptr4 = ptr1; //should compilation error

	uniquePtr<int> ptr5;
	//ptr5 = ptr1; //should compilation error


	uniquePtr<int> ptr6 = std::move(ptr2);

	uniquePtr<int> ptr7;
	ptr7 = std::move(ptr6);

	//ptr7->fun();

	ptr7.get();
	ptr7.reset(new int(10));
	std::cout << *ptr7 << '\n';


}