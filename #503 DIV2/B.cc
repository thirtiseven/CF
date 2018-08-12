#include <iostream>
#include <algorithm>
#include <cstring>

const int maxn = 1008;

int vis[maxn];

int main(int argc, char *argv[]) {  
	int n, p[maxn];
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		int a = i;
		while (!vis[a]) {
			vis[a] = 1;
			a = p[a];
		}
		std::cout << a << ' ';
	}
}