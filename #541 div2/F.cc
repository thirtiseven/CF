#include <iostream>

const int maxn = 150000+7;

int fa[maxn], l[2*maxn], r[2*maxn], gao[maxn];
int n, u, v;

void init(int n) {
	for (int i = 1; i <= n; i++) fa[i] = i, gao[i] = i;
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}

void print(int x) {
	if (x <= n) {
		std::cout << x << ' ';
	} else {
		print(l[x]);
		print(r[x]);
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	int tot = n+1;
	init(n);
	for (int i = 1; i < n; i++) {
		std::cin >> u >> v;
		l[tot] = gao[find(u)];
		r[tot] = gao[find(v)];
		gao[find(u)] = tot;
		gao[find(v)] = tot;
		unin(u, v);
//		std::cerr << u << ' ' << v << ' ' << l[tot] << ' ' << r[tot] << ' ' << tot << '\n';
		tot++;
	}
	tot--;
	print(tot);
}