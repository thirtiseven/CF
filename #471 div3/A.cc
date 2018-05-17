#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {  
	int n, a[55];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> aa;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool yes = 1;
		for (int j = i+1; j < n; j++) {
			if (a[i] == a[j]) {
				yes = 0;
			}
		}
		if (yes) {
			cnt++;
			aa.push_back(a[i]);
		}
	}
	std::cout << cnt << '\n';
	for (auto i: aa) {
		std::cout << i << " ";
	}
}