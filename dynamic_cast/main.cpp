#include <iostream>

class Base {
public:
	virtual void foo() {
		std::cout << "Base foo \n";
	}
};

class Derived : public Base {
public:
	void foo() override{
		std::cout << "Derived foo \n";
	}
	void bar() {
		std::cout << "Derived bar \n";
	}
};


class Entity {
public:
	virtual void fun(){}

};
class Player : public Entity {
public:
	void fun() { std::cout << "Player fun\n"; }
	void fun1() { std::cout << "Player fun1\n"; }
};
class Enemy : public Entity {
public:
	void fun() { std::cout << "Enemy fun\n"; }
	void fun1() { std::cout << "Enemy fun1\n"; }
};

int main() {

	Base* b = new Derived;
	
	static_cast<Derived*>(b)->bar();

	Derived* d = dynamic_cast<Derived*>(b);
	if (d != nullptr) {
		d->bar();
	}

	Entity* e1 = new Enemy();
	Player* p1 = new Player();
	Entity* e2 = p1;


	Player* p = dynamic_cast<Player*>(e1);

	if (p != nullptr) {
		std::cout << "NOT NULL \n";
		p->fun1();
	}
	else {
		std::cout << "NULL \n";
	}

	// If we use static_cast, there can be issue for below case.

	Player* p2 = static_cast<Player*>(e1);
	
	p2->fun1(); // will execute & print "Player fun" 
	//although we casting enemy object to player object which is wrong
	// so, we need to use dynamic_cast , it will assign nullptr if cast failed.

	Player* p3 = dynamic_cast<Player*>(e1);
	p3->fun1();
	if (p3 != nullptr) {
		p3->fun1();
	}
	else {
		std::cout << "Nullptr \n";
	}

}