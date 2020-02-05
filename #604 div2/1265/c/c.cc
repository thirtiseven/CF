#include <iostream>
#include <vector>

const int maxn = 4e5+7;

int T, n, p[maxn];
std::vector<int> num;
int ans1, ans2, ans3;

bool check(int x) {
	bool yes = 1;
	int sum = 0;
	for (int i = 0; i < x; i++) {
		sum += num[i];
	}
	ans1 = sum;
	int cp;
	int cur = 0;
	for (int i = x; i < num.size(); i++) {
		cur += num[i];
		if (cur > sum) {
			cp = i;
			break;
		}
	}
	if (cur <= sum) {
		return false;
	}
	ans2 = cur;
	cur = 0;
	for (int i = cp+1; i < num.size(); i++) {
		cur += num[i];
		if (ans1 + ans2 + cur > n/2) {
			cur -= num[i];
			break;
		}
	}
	if (cur <= sum) {
		return false;
	}
	if (ans1 + ans2 + cur > n/2) {
		return false;
	}

	ans3 = cur;
	return true;
}

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		num.clear();
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> p[i];
		}
		int cur = 1;
		for (int i = 1; i < n; i++) {
			if (p[i] == 0) {
				break;
			}
			if (p[i] == p[i-1]) {
				cur++;
			} else {
				num.push_back(cur);
				cur = 1;
			}
		}
		num.push_back(cur);
		if (!check(1)) {
			std::cout << "0 0 0\n";
			continue;
		}
		int l = 1, r = num.size(), mid;
		while (l <= r) {
			mid = (l+r)/2;
			if (check(mid)) {
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		while (!check(l)) {
			l--;
		}
		std::cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
	}
}