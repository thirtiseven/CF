#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int pos[maxn], a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		pos[a[i]] = i;
	}
	int cur = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
		if (pos[b[i]] < cur) {
			std::cout << "0 ";
		} else {
			std::cout << pos[b[i]]-cur << " ";
			cur = pos[b[i]];
		}
	}
}