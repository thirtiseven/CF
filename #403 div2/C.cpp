#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

std::vector <int> c[200010];

int colour[200010];

int n, cnt = 0;
int colnow;


void dfs(int po, int cnt) {
	if(colour[po]) {
		return;
	}
	for(int i = 1; i < n; i++) {
		if(i==)
		for(std::vector<int>::iterator it=c[po].begin();it!=c[po].end();it++) {
			if(i==colour[*it]) {
				continue;
			}
		}
		colour[po] = i;
		break;
	}
	for(int i = 0; i < po;i++) {}
	for(std::vector<int>::iterator it=c[po].begin();it!=c[po].end();it++) {
		dfs(*it, cnt++);
	}
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false); 
	int s, t;
	std::cin >> n;
	for(int i=1; i < n ; i++) {
		std::cin >> s >> t;
		c[s].push_back(t);
		c[t].push_back(s);
	} 
	colour[1] = 1;
	dfs(1, 1);
	for(int i = 0; i < n; i++) {
		std::cout << colour[i] << " ";
	}
	return 0;
}