#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


int main() {

	auto add = [](int x, int y) {
		return x + y;
	};
	cout << add(10, 20) << '\n';

	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	
	auto totalSum = [=]() {
		int sum = 0;
		for (auto& x : v)
			sum += x;
		return sum;
	};

	cout << totalSum() << '\n';

	auto totalSumAccumulate = accumulate(v.begin(), v.end(), 0, [](int a, int b) {
			return a + b;
	});
	auto EvenSum = accumulate(v.begin(), v.end(), 0, [](int acc, int x) {
		return x % 2 == 0 ? acc + x : acc;
	});


	cout << totalSumAccumulate << '\n';
	cout << EvenSum << '\n';

}
