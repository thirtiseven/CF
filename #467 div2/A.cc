#include <iostream>
#include <algorithm>
#include <set>

std::set<int> aa;

int main(int argc, char *argv[]) {  
	int n, a[109];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i]) aa.insert(a[i]);
	}
	std::cout << aa.size();
}