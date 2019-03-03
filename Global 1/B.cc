#include <iostream>
#include <algorithm>
#include <queue>

const int maxn = 1e5+7;

int n, m, k;
int a[maxn];
std::priority_queue<int> p;

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		p.push(a[i]-a[i-1]-1);
	}
	int ans = a[n-1] - a[0] + 1;
	for (int i = 0; i < k-1; i++) {
		ans -= p.top();
		p.pop();
	}
	std::cout << ans;
}
