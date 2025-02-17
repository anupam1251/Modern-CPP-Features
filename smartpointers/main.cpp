#include <iostream>
#include <memory>

class Myclass {
	int m_val;
public:
	Myclass(int val): m_val(val) {
		std::cout << "Constructor invoked" << '\n';
	}
	~Myclass() {
		std::cout << "Destructor invoked" << '\n';
	}
	int getVal() const {
		return m_val;
	}
};

int main() {

	std::unique_ptr<Myclass	> unptr1 = std::make_unique<Myclass>(25);
	std::unique_ptr<Myclass> unptr2 = std::move(unptr1); //owernership changed and unptr1 is nullptr now 
	std::cout << unptr2->getVal() << '\n';

	std::shared_ptr<Myclass> shptr1 = std::make_shared<Myclass>(10);
	std::cout <<"ref count : "<< shptr1.use_count() << '\n';
	{
		std::shared_ptr<Myclass> shptr2 = shptr1;
		std::cout << "ref count : " << shptr1.use_count() << '\n';
	}
	std::cout << "ref count : " << shptr1.use_count() << '\n';


	std::weak_ptr<Myclass> wkptr1;
	{
		std::shared_ptr<Myclass> shptr2 = std::make_shared<Myclass>(25);
		wkptr1 = shptr2;
	}

	return 0;
}