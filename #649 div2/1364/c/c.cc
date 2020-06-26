#include <iostream>
#include <algorithm>
#include <set>

const int maxn = 1e5+7;

int n, a[maxn], b[maxn];
std::set<int> s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		b[i] = -1;
	}
	for (int i = n; i >= 1; i--) {
		if (s.count(a[i]) == 0) {
			b[i+1] = a[i];
			s.insert(a[i]);
		}
	}
	int now = 0;
	while (s.count(now)) {
		now++;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] == -1) {
			b[i] = now;
			now++;
			while (s.count(now)) {
				now++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		std::cout << b[i] << " \n"[i==n];
	}
}