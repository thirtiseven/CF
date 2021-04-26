#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

const int maxn = 2e5+7;

int t, n, k, a[maxn];

std::vector<int> sq;

void square() {
	for (int i = 2; i * i <= 10000000; i++) {
		sq.emplace_back(i*i);
//		sqs.insert(i*i);
	}
}

std::set<int> s, sqs;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	square();
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		s.clear();
		int ans = 1;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			for (auto it: sq) {
				while (a[i] % it == 0) {
					a[i] /= it;
				}
			}
			if (s.count(a[i])) {
				ans++;
				s.clear();
				s.insert(a[i]);
			} else {
				s.insert(a[i]);
			}
		}
		std::cout << ans << '\n';
	}
}