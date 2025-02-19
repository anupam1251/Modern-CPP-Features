#include <iostream>
#include <string>

//Here class manages dynamically allocated memory
// Rules of 5 
//1. Copy constructor
//2. Copy assignment
//3. Destructor
//4. Move constructor
//5. Move assignment

class Employee {
	char* m_name;
	size_t m_age;
public:
	explicit Employee() : m_name(nullptr) , m_age(0) {
		std::cout << "Default constructor" << '\n';
	}

	Employee(const char* name, const size_t& age)  : m_age(age){
		size_t len = strlen(name) + 1;
		m_name = new char[len];
		strcpy_s(m_name, len, name);
		std::cout << "parametrized constructor invoked" << '\n';
	}

	Employee(const Employee& obj) : m_age(obj.m_age) {
		size_t len = strlen(obj.m_name) + 1;
		m_name = new char[len];
		strcpy_s(m_name, len, obj.m_name);
		std::cout << "Copy constructor invoked" << '\n';

	}

	Employee& operator= (const Employee& obj) {
		if (this != &obj) {
			delete[]m_name;

			size_t len = strlen(obj.m_name) + 1;
			m_name = new char[len];
			strcpy_s(m_name, len, obj.m_name);
			m_age = obj.m_age;
		}
		std::cout << "Copy assignment operator called" << '\n';
		return *this;
	}

	Employee(Employee&& obj) : m_name(obj.m_name), m_age(obj.m_age) {
		obj.m_name = nullptr;
		std::cout << "Move constructor invoked" << '\n';
	}

	Employee& operator= (Employee&& obj) {
		if (this != &obj) {
			delete[] m_name;
			m_name = obj.m_name;
			obj.m_name = nullptr;

			m_age = obj.m_age;
		}
		std::cout << "Move assignment operator called" << '\n';
		return *this;
	}

	~Employee() {
		delete[] m_name;
	    std::cout << "destructor invoked" << '\n';
	}

	void getData() {
		std::cout << "[ Name : " << m_name << " , Age : " << m_age<<" ]" << '\n';
	}


};
int main() {
	Employee e1;
	Employee e2("Anupam Chaudhary", 26); e2.getData();
	Employee e3 = e2; e3.getData();
	Employee e4; 
	e4 = e3;  e4.getData();
	Employee e5 = std::move(e4); e5.getData();
	Employee e6;
	e6 = std::move(e5); e6.getData();
}