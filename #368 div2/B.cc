#include <iostream>
#include <algorithm>
#include <cstring>

#define ll long long
#define maxn 100010
#define inf 0x7f7f7f7f

struct city {
	ll u, v, l;
}c[maxn];

bool f[maxn];
ll m, n, k;

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		std::cin >> c[i].u >> c[i].v >> c[i].l;
	}
	ll temp;
	memset(f, 0, sizeof(f));
	for(int i = 0; i < k; i++) {
		std::cin >> temp;
		f[temp] = true;
	}
	ll minn = inf;
	for(int i = 1; i <= m; i++) {
		if(f[c[i].v]^f[c[i].u]) {
			minn = std::min(minn, c[i].l);
		}
	}
	if(minn == inf) {
		std::cout << "-1\n";
	} else {
		std::cout << minn << '\n';
	}
	return 0;
}