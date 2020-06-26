#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

const int maxn = 1024;
int n, in[maxn], u, v, w;
std::queue<int> leaf;
std::set<int> check;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::fill(in, in+maxn, 0);
	std::cin >> n;
	for (int i = 0; i < n-1; i++) {
		std::cin >> u >> v;
		in[u]++;
		in[v]++;
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 1) {
			leaf.push(i);
			check.insert(i);
		}
	}
	int now = 0;
	while (1) {
		u = leaf.front();
		leaf.pop();
		check.erase(u);
		v = leaf.front();
		leaf.pop();
		check.erase(v);
		std::cout << "? " << u << ' ' << v << std::endl;
		std::cin >> w;
		if (check.count(w) == 0) {
			check.insert(w);
			leaf.push(w);
		}
		if (leaf.size() == 1) {
			std::cout << "! " << w << std::endl;
			exit(0);
		}
	}
}