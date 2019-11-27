#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e6+7;
int n, a[maxn], s[maxn], cnt[maxn];
std::vector<int> now;
std::vector<int> ans;

int main(int argc, char *argv[]) {  
	std::fill(s, s+maxn, 0);
	std::fill(cnt, cnt+maxn, 0);
	std::cin >> n;
	int num = 0;
	bool yes = 1;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];;
	}
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur++;
		if (a[i] > 0) {
			if (s[a[i]] == 1 || cnt[a[i]] > 0) {
				yes = 0;
				break;
			}
			s[a[i]] = 1;
			now.push_back(a[i]);
			cnt[a[i]]++;
			num++;
		} else {
			if (s[-a[i]] == 0) {
				yes = 0;
				break;
			} else {
				s[-a[i]] = 0;
				num--;
			}
		}
		if (num == 0) {
			ans.push_back(cur);
			for (auto it: now) {
				cnt[it]--;
			}
			now.clear();
			cur = 0;
		}
	}
	if (yes == 0 || num > 0) {
		std::cout << "-1\n";
		exit(0);
	}
	if (cur > 0) ans.push_back(cur);
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << it << ' ';
	}
}