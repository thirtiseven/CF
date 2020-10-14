#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1007;

int T, n, a[maxn], tot[maxn];

int mex() {
	int res = 0;
	while (tot[res] > 0) {
		res++;
	}
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		std::fill(tot, tot+n+1, 0);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			tot[a[i]]++;
		}
		std::vector<int> ans, zero;
		for (int i = 1; i <= n; i++) {
			if (a[i] != 0) {
				ans.push_back(i);
				int temp = a[i];
				a[i] = mex();
				tot[temp]--;
				tot[a[i]]++;
			} else {
				zero.push_back(i);
			}
		}
		for (auto it: zero) {
			int temp = a[it];
			a[it] = mex();
			tot[temp]--;
			tot[a[it]]++;
		}
		std::cout << "----------\n";
		for (int i = 1; i <= n; i++) {
			std::cout << a[i] << ' ';
		}
		std::cout << '\n';
		for (int i = 1; i <= n; i++) {
			int pos = mex();
//			std::cout << i << ' ' << pos << '\n';
			if (pos >= n) {
				pos = n-1;
			}
			ans.push_back(pos+1);
			int temp = a[pos+1];
			a[pos+1] = pos;
			tot[temp]--;
			tot[pos]++;
		}
		for (int i = 1; i <= n; i++) {
			std::cout << a[i] << ' ';
		}
		std::cout << '\n';
		std::cout << "----------\n";
		std::cout << ans.size() << '\n';
		for (auto it: ans) {
			std::cout << it << ' ';
		}
		std::cout << '\n';
	}
}