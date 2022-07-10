#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 503;
const int inf = 5000;

int T, n;
int A[maxn][maxn], B[maxn][maxn], R[maxn], C[maxn];

int fa[maxn];

void init(int n) {
	for (int i = 1; i <= n; i++) fa[i] = i;
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}

int sum;
std::vector<std::pair<int, std::pair<int, int>>> v;

int preprocess() {
	v.clear();
	sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i][j] == -1) {
				sum += B[i][j];
				v.push_back(std::make_pair(B[i][j], std::make_pair(i, j+n)));
			}
		}
	}
	init(2*n);
	std::sort(v.begin(), v.end());
	std::reverse(v.begin(), v.end());
	for (auto it: v) {
		int x = it.second.first, y = it.second.second;
		if (find(x) != find(y)) {
			sum -= it.first;
			unin(x, y);
		}
	}
	return sum;
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CASE = 1; CASE <= T; CASE++) {
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				std::cin >> A[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				std::cin >> B[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> R[i];
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> C[i];
		}
		std::cout << "Case #" << CASE << ": " << preprocess() << '\n';
	}
}