#include <iostream>

using ll = long long;

const int maxn = 2e5+7;

int n, u, v;
int x[2*maxn], pre[2*maxn];
int tot = 0;
std::pair<int, int> s[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i].first >> s[i].second;
		x[s[i].first] = i;
		x[s[i].second] = i;
	}
	pre[0] = 0;
	for (int i = 1; i <= 2*n; i++) {
		pre[i] = pre[i-1]^x[i];
	}
	for (int i = 1; i <= n; i++) {
		sum += (s[i].second-s[i].first-1);
	}
}