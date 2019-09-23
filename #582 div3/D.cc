#include <iostream>
#include <algorithm>

const int maxn = 4e5+7;

int n, k, a[maxn], num[maxn], mov[maxn];
int ans = 1e9;

void dfs(int now) {
	if (now > 2e5) {
		return;
	}
	if (now != 0) dfs(now*2);
	mov[now] = num[now*2] + mov[now*2];
	num[now] += num[now*2];
	if (num[now] >= k) {
		ans = std::min(mov[now], ans);
	}
	dfs(now*2+1);
	mov[now] += num[now*2+1] + mov[now*2+1];
	num[now] += num[now*2+1];
	if (num[now] >= k) {
		ans = std::min(mov[now], ans);
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	std::fill(num, num+maxn, 0);
	std::fill(mov, mov+maxn, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		num[a[i]]++;
	}
	dfs(0);
	std::cout << ans << '\n';
}