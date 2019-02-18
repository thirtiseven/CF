#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;

int n, a[maxn], b[maxn];
std::map<int, int> mp;
std::vector<int> ans[maxn];
int cnt[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		mp[n-a[i]]++;
	}
	bool yes = 1;
	int now = 1;
	for (auto it: mp) {
//		std::cout << it.first << " " << it.second << '\n';
		if (it.second % it.first == 0) {
			for (int i = 0; i < it.second/it.first; i++) {
				for (int j = 0; j < it.first; j++) {
					ans[it.first].push_back(now);
				}
				now++;
			}
		} else {
			std::cout << "Impossible\n";
			exit(0);
		}
	}
	std::fill(cnt, cnt+maxn, 0);
	for (int i = 0; i < n; i++) {
		b[i] = ans[n-a[i]][cnt[a[i]]];
		cnt[a[i]]++;
	}
	if (yes) {
		std::cout << "Possible\n";
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			std::cout << b[i] << " ";
		}
	}
}