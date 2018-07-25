#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

const int maxn = 123;

int main(int argc, char *argv[]) {  
	int n, k, t, q[maxn];
	std::fill(q, q+maxn, -1);
	std::set<std::pair<int, int>> a;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> t;
		q[t] = i;
	}
	int cnt = 0;
	for (int i = 1; i <= 100; i++) {
		if (q[i] != -1) {
			cnt++;
		}
	}
	if (cnt < k) {
		std::cout << "NO\n";
	} else {
		cnt = 0;
		std::cout << "YES\n";
		for (int i = 1; i <= 100 && cnt < k; i++) {
			if (q[i] != -1) {
				std::cout << q[i] << " ";
				cnt++;
			}
		}
	}
}