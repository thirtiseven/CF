#include <iostream>

const int maxn = 4e5+7;
int a[maxn];

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i+n] = a[i];
	}
	int ans = 0;
	int now = 0;
	for (int i= 0; i< 2*n; i++) {
		if (a[i] == 1) {
			now++;
		} else {
			ans = std::max(now, ans);
			now = 0;
		}
	}
	std::cout << ans;
}