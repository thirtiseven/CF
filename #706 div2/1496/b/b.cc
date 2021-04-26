#include <iostream>
#include <algorithm>
#include <set>

const int maxn = 1e5+7;

int t, n, k, a[maxn];
int cur = 0;
std::set<int> s;

int mex() {
	while (s.count(cur) != 0) {
		cur++;
	}
	return cur;
}

int max() {
	return *s.rbegin();
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		s.clear();
		cur = 0;
		std::cin >> n >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			s.insert(a[i]);
		}
		int ans = 0, last_mex = -1;
		for (int i = 0; i < k; i++) {
			last_mex = mex();
			s.insert((max()+mex()+1)/2);
			if (mex() == last_mex) {
				break;
			}
			if (mex() > max()) {
				std::cout << s.size() + k - 1 - i << '\n';
				goto end;
			}
		}
		std::cout << s.size() << '\n';
		end:;
	}
}