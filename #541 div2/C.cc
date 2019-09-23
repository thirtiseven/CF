#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 103;

int n, a[maxn];
std::vector<int> buffer;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	for (int i = 0; i < n; i++) {
		if (i%2==0) {
			std::cout << a[i] << ' ';
		} else {
			buffer.push_back(a[i]);
		}
	}
	std::reverse(buffer.begin(), buffer.end());
	for (auto it: buffer) {
		std::cout << it << ' ';
	}
}