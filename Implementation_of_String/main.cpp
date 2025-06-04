#include <iostream>
using namespace std;
class String {
	char* m_res;
	size_t m_len;
public:
	String() : m_res(nullptr), m_len(0){}

	String(const char* str) {
		m_len = strlen(str);
		m_res = new char[m_len + 1];
		strcpy_s(m_res, m_len+1, str);
	}

	String(const String& obj) {
		m_len = strlen(obj.m_res);
		m_res = new char[m_len + 1];
		strcpy_s(m_res, m_len + 1, obj.m_res);
	}

	String& operator=(const String& obj) {
		if (this != &obj) {
			if (m_res) {
				delete []m_res;
			}
			m_len = strlen(obj.m_res);
			m_res = new char[m_len + 1];
			strcpy_s(m_res, m_len + 1, obj.m_res);
		}
		return *this;
	}

	String(String&& obj) {
		m_res = obj.m_res;
		m_len = obj.m_len;
		obj.m_res = nullptr;
		obj.m_len = 0;
	}

	String& operator=(String&& obj) {
		if (this != &obj) {
			if (m_res)
				delete[] m_res;
			m_res = obj.m_res;
			m_len = obj.m_len;
			obj.m_res = nullptr;
			obj.m_len = 0;
		}
		return *this;
	}

	~String() {
		cout << "destructor invoked" << '\n';
		delete []m_res;
	}

	int size() const{
		return m_len;
	}

	friend ostream& operator<<(ostream& out, const String& obj);
	friend istream& operator>>(istream& in, String& obj);
};

ostream& operator<<(ostream& out, const String& obj) {
	out << obj.m_res;
	return out;
}

istream& operator>>(istream& in, String& obj) {
	char* buffer = new char[1000]; // can be increased if needed

	in >> buffer;
	delete[] obj.m_res;

	obj.m_len = strlen(buffer);
	obj.m_res = new char[obj.m_len + 1];

	strcpy_s(obj.m_res, obj.m_len+1, buffer);

	delete buffer;
	return in;
}

int main() {
	String obj1 =  "Anupam";

	String obj2(obj1);

	obj2 = "Student";
	cout << obj2 << '\n';
	cout << obj1 << '\n';
	cin >> obj1;
	cout << obj1 << '\n';
}