#include <iostream>

template<class T>
T square(T input) {
	return input * input;
}

auto square2(auto input) {
	return input * input;
}

template<typename T1, typename T2>
void foo(T1 input1, T2 input2) {
	std::cout << typeid(input1).name() << std::endl;
	std::cout << typeid(input2).name() << std::endl;
}

template<typename T>
bool equal(T a, T b) {
	return (a == b);
}

template<>
bool equal<float>(float a, float b) {
	std::cout << "equal<float>" << std::endl;
	return fabs(a-b) < 0.0001f;
}

template<typename T1, typename T2>
auto Max(T1 x, T2 y) -> typename std::common_type<T1, T2>::type{
	return x > y ? x : y;
}

template<typename T>
T ArraySum(const T* pArr, size_t arrSize) {
	T ans = 0;
	for (int i = 0; i < arrSize; i++) {
		ans += *(pArr + i);
	}
	return ans;
}

template<typename T>
T Max(const T* pArr, size_t arrSize) {

	T ans = INT_MIN;
	for (int i = 0; i < arrSize; i++) {
		ans = std::max(ans, *(pArr + i));
	}
	return ans;
}

template<typename T>
std::pair<const T&, const T&> MinMax(const T* pArr, size_t arrSize) {
	T s_elem = INT_MAX, l_elem = INT_MIN;
	for (int i = 0; i < arrSize; i++) {
		s_elem = std::min(s_elem, *(pArr + i));
		l_elem = std::max(l_elem, *(pArr + i));
	}
	return std::make_pair(s_elem, l_elem);
}

template<typename T1, typename T2>
auto max(const T1 &a, const T2 &b) ->decltype(b<a?a:b)
{
	std::cout << "using Global max() ";
	return b < a ? a : b;
}

namespace Mynamespace {
	template<class T>
	T max(T a, T b)
	{
		std::cout << "Using MyNameSpace max() ";
		return b < a ? a : b;
	}

}

template<typename T>
T* foo(T*) {
	return nullptr;
}
int main() {
	
	std::cout << square(5) << std::endl;
	std::cout << square(5.5) << std::endl;
	std::cout << square(6.5f) << std::endl;
	std::cout << square<double>(10.5) << std::endl;

	std::cout << square2(7) << std::endl;

	foo<int, float>(10, 3.5);

	std::cout << equal<int>(2, 2) << std::endl;
	std::cout << equal<int>(2, 3) << std::endl;

	std::cout << equal<float>(1.0f- 0.999999f, 0.000001f) << std::endl;
	std::cout << equal<float>(2.5f,3.5f) << std::endl;

	std::cout << Max(10, 20) <<"\n";
	std::cout << Max(10.2f, 20.4f) <<"\n";
	std::cout << Max(10, 20.4) << "\n";

	int arr1[5] = { 1,2,3,4,15 };
	std::cout << "ArraySum : " << ArraySum(arr1, 5) << "\n";

	double arr2[5] = { 1.14,2.1,3.3,4.2,5.2 };
	std::cout << "ArraySum : " << ArraySum(arr2, 5) << "\n";

	std::cout << "arr1 Max : " << Max(arr1, 5) << "\n";
	std::cout << "arr2 Max : " << Max(arr2, 5) << "\n";


	std::cout << "MinMax of arr1 : " << MinMax(arr1, 5).first<<" " <<MinMax(arr1,5).second << "\n";
	std::cout << "MinMax of arr2 : " << MinMax(arr2, 5).first << " " << MinMax(arr2, 5).second << "\n";
	
	int i = 42;

	std::cout << "max(7,i): " << max(7, i) << '\n';
	std::cout << "max(7,i): " << ::max(7, i) << '\n';
	double f1 = 3.4;
	double f2 = -6.7;
	std::cout << "max(f1,f2): " << ::max(f1, f2) << '\n';
	std::string s1 = "mathematics";
	std::string s2 = "math";
	std::cout << "max(s1,s2): " << ::max(s1, s2) << '\n';

	void* vp = nullptr;
	std::cout << foo(vp) << '\n';

	std::cout << max(static_cast<double> (5), 5.2) << '\n';
	std::cout << max<double>(5, 5.2) << '\n';

	std::cout << max(6.1, 5.2) << '\n';

	return 0;
}