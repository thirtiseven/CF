#include <iostream>
#include <vector>

const int maxn = 2e5+7;

int a[maxn], vis[maxn];
std::vector<int> ans;

int main(int argc, char *argv[]) {  
	std::fill(vis, vis+maxn, 0);
	int n, k;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
	}
	
	for (int i = n-1; i >= 0; i--) {
		if (!vis[a[i]] && ans.size() < k) {
			vis[a[i]] = 1;
			ans.push_back(a[i]);
		}
	}
	
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << it << ' ';
	}
}