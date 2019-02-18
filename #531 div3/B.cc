#include <iostream>
#include <vector>

const int maxn = 5007;

int n, k;
int a[maxn], ans[maxn];
std::vector<int> pos[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		pos[a[i]].push_back(i);
	}
	bool yes = 1;
	for (int i = 1; i <= k; i++) {
		if (pos[i].size() > k) {
			yes = 0;
			break;
		}
	}
	if (!yes) {
		std::cout << "NO\n";
		exit(0);
	}
	int lab = 0;
	for (int i = 1; i <= 5000; i++) {
		for (auto it: pos[i]) {
			ans[it] = lab+1;
			lab = (lab+1)%k;
		}
	}
	std::cout << "YES\n";
	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " ";
	}
}