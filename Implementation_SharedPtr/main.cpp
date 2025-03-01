#include <iostream>

template<typename T>
class SharedPtr {
	T* m_res;
	int* m_counter;

	void incrementCounter() {
		if (m_counter)
			(*m_counter)++;
	}

	void decrementCounter() {
		if (m_counter) {
			(*m_counter)--;
			if (*m_counter == 0) {
					delete m_res;
					delete m_counter;
			}
		}
	}


public:

	SharedPtr<T>(T* ptr = nullptr) : m_res(ptr), m_counter(ptr ? new int(1) : nullptr) {
		std::cout << "default/param. constructor invoked" << std::endl;
	}

	SharedPtr<T>(const SharedPtr<T>& ptr) {
		m_res = ptr.m_res;
		m_counter = ptr.m_counter;
		incrementCounter();
		std::cout << "copy constructor invoked" << std::endl;
	}

	SharedPtr<T>(SharedPtr<T>&& ptr) {
		m_res = ptr.m_res;
		m_counter = ptr.m_counter;
		ptr.m_res = nullptr;
		ptr.m_counter = nullptr;
		std::cout << "Move constructor invoked" << std::endl;
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& ptr) {
		if (this != &ptr) {
			decrementCounter();
			m_res = ptr.m_res;
			m_counter = ptr.m_counter;
			incrementCounter();
		}	
		std::cout << "copy assignment operator invoked" << std::endl;
		return *this;
	}

	SharedPtr<T>& operator=(SharedPtr<T>&& ptr) {
		if (this != &ptr) {
			decrementCounter();
			m_res = ptr.m_res;
			m_counter = ptr.m_counter;

			ptr.m_res = nullptr;
			ptr.m_counter = nullptr;
		}
		std::cout << "move assignment operator invoked" << std::endl;
		return *this;
	}

	void reset(T* ptr = nullptr) {
		decrementCounter();
		m_res = ptr;
		m_counter = ptr ? new int(1) : nullptr;
	}

	T* get() {
		return m_res;
	}

	T& operator*() {
		if (!m_res)
			throw std::runtime_error("dereferencing nullptr");
		return *m_res;
	}

	int getCount() {
		return m_counter ? *m_counter : 0;
	}

	T* operator->() {
		return m_res;
	}

	~SharedPtr() {
		decrementCounter();
		std::cout << "destructor invoked" << std::endl;
	}
};

int main() {


	SharedPtr<int> ptr1;
	//std::cout << *ptr1 << std::endl;
	SharedPtr<int> ptr2(new int(10));
	SharedPtr<int> ptr3(ptr1);
	SharedPtr<int> ptr4(std::move(ptr2));

	ptr4 = ptr1;
	ptr4 = std::move(ptr3);

	ptr4.reset();
	ptr4.reset(new int(20));

	ptr4.get();
	std::cout << *ptr4 << std::endl;

	std::cout << ptr4.getCount() << std::endl;;
	

	//ptr4->func();
}