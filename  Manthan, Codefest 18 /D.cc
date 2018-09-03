#include <iostream>
#include <set>
#include <vector>
#include <queue>

const int maxn = 2e5+7;

std::queue<int> q;
std::queue<int> f;
std::vector<int> t[maxn];
int a[maxn];
int dep[maxn], fa[maxn];

int main(int argc, char *argv[]) {  
	std::fill(dep, dep+maxn, 0);
	int n, u, v;
	std::cin >> n;
	for (int i = 0; i < n-1; i++) {
		std::cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	if (a[1] != 1) {
		std::cout << "No\n";
		exit(0);
	}
	int tot = 1;
	int now = 0;
	q.push(1);
	dep[1] = 1;
	fa[1] = 0;
	while (!q.empty()) {
		int tt = q.front();
		q.pop();
		for (auto it: t[tt]) {
			if (!dep[it]) {
				q.push(it);
				dep[it] = dep[tt] + 1;
				fa[it] = tt;
			}
		}
	}
	f.push(1);
	for (int i = 2; i <= n; i++) {
		if (dep[a[i]] < dep[a[i-1]]) {
			std::cout << "No\n";
			exit(0);
		}
		while (fa[a[i]] != f.front()) {
			f.pop();
			if (f.empty()) {
				std::cout << "No\n";
				exit(0);
			}
		}
		f.push(a[i]);
	}
	std::cout << "Yes\n";
}