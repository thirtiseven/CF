#include <iostream>
#include <algorithm>
#define inf 0x7f7f7f7f
const int maxn = 1e5+9;

int main(int argc, char *argv[]) {  
	int a[maxn], n, minn = inf, mind = inf;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		minn = std::min(minn, a[i]);
	}
	int o1 = -1000000, o2;
	for(int i = 0; i < n; i++) {
		if(a[i] == minn) {
			mind = std::min(i - o1, mind);
			o1 = i;
		}
	}
	std::cout << mind;
	return 0;
}