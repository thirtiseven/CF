#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int n;
int ans[maxn];
std::pair<int, int> e[maxn];
int in[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::fill(in, in+maxn, 0);
	std::fill(ans, ans+maxn, -1);
	std::cin >> n;
	for (int i = 0; i < n-1; i++) {
		std::cin >> e[i].first >> e[i].second;
		in[e[i].first]++;
		in[e[i].second]++;
	}
	int pos = -1, maxx = 0;
	for (int i = 1; i <= n; i++) {
		if (in[i] > maxx) {
			pos = i;
			maxx = in[i];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n-1; i++) {
		if (e[i].first == pos || e[i].second == pos) {
			ans[i] = cnt;
			cnt++;
		}
	}
	for (int i = 0; i < n-1; i++) {
		if (ans[i] == -1) {
			ans[i] = cnt;
			cnt++;
		}
	}
	for (int i = 0; i < n-1; i++) {
		std::cout << ans[i] << '\n';
	}
}