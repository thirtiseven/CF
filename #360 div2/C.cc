#include <iostream>
#include <vector>
#include <cstring>
#define maxn 100010

std::vector<int> p[maxn], alice, bob;
int col[maxn];
bool flag = 1;

void dfs(int node, int colour) {
	if(col[node] != 0) {
		if(col[node] != colour) {
			flag = 0;
		}
		return;
	}
	col[node] = colour;
	if(colour == 1) {
		alice.push_back(node);
	} else if(colour == 2){
		bob.push_back(node);
	}
	for(std::vector<int>::iterator it = p[node].begin(); it != p[node].end(); it++) {
		dfs(*it, 3-colour);
	}
}

int main(int argc, char *argv[]) {  
	int n, m, u, v;
	std::cin >> n >> m;
	memset(col, 0, sizeof(col));
	for(int i = 0; i < m; i++) {
		std::cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		if(!col[i] && !p[i].empty()) {
			dfs(i, 1);
		}
	}
	if(!flag) {
		std::cout << "-1\n";
	} else {
		std::cout << bob.size() << '\n';
		for(std::vector<int>::iterator it = bob.begin(); it != bob.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << '\n' << alice.size() << '\n';
		for(std::vector<int>::iterator it = alice.begin(); it != alice.end(); it++) {
			std::cout << *it << " ";
		}
	}
	return 0;
}