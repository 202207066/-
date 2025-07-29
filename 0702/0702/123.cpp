#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class isEvon {
	bool operator()(int n) {
		return n % 2 == 0;

	}
};

int main() {
	vector<int> v = { 1,2,3,4,5 };
	int count = count_if(v.begin(), v.end(), isEvon());
	cout << "Â¦¼ö °³¼ö" << count;
}
