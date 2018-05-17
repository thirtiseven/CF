#include <iostream>
#include <map>
#include <algorithm>

const int maxn = 2e5+9;

int main(int argc, char *argv[]) {  
	std::map<int, int> ans;
	int n, a[maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int maxx = 1, num = a[0];
	for (int i = 0; i < n; i++) {
		ans[a[i]] = 1;
		if (ans.find(a[i]-1) != ans.end()) {
			ans[a[i]] = ans[a[i]-1] + 1;
			if (ans[a[i]] > maxx) {
				maxx = ans[a[i]];
				num = a[i];
			}
		}
	}
	int start = num - maxx + 1;
	std::cout << maxx << '\n';
	for (int i = 0; i < n; i++) {
		if (a[i] == start) {
			std::cout << i+1 << " ";
			start++;
		}
	}
}