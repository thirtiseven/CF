#include <iostream>

struct point {
	int x, y, id;
}p[109];

int fa[109];

void init(int n) {
	for (int i = 1; i <= n; i++) fa[i] = i;
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	init(n);
	for(int i = 1; i <= n; i++) {
		std::cin >> p[i].x >> p[i].y;
		p[i].id = i;
		for(int j = 1; j <= i; j++) {
			if(p[j].x == p[i].x || p[j].y == p[i].y) {
				unin(i, j);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(find(i) == i) {
			ans++;
		}
	}
	std::cout << ans-1 << std::endl;
	return 0;
}