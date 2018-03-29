#include <queue> 
#include <cstring> 
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector> 
#define maxn 1007 
#define INF 0x7FFFFFFF 
using namespace std;

int d[maxn], ds[maxn];
bool inq[maxn]; 
vector<int> G[maxn];

void SPFA(int s){ 
	queue<int> q;
	memset(inq,0,sizeof(inq)); 
	for(int i=0;i<maxn;++i)
		d[i]=INF; 
	d[s]=0;
	inq[s]=1; 
	q.push(s);
	int u; 
	while(!q.empty()){
		u=q.front(); 
		q.pop(); 
		inq[u]=0;
		for(auto e: G[u]) {
			if(d[e]>d[u]+1){
				d[e]=d[u]+1; 
				if(!inq[e]){
					q.push(e);
					inq[e]=1; 
				}
			} 
    	}
	}	
}

int main(int argc, char *argv[]) {  
	int n, m, s, t;
	std::cin >> n >> m >> s >> t;
	s--, t--;
	int tempn, tempm;
	for (int i = 0; i < m; i++) {
		std::cin >> tempn >> tempm;
		G[tempn-1].push_back(tempm-1);
		G[tempm-1].push_back(tempn-1);
	}
	SPFA(s);
	for (int i = 0; i < n; i++) {
		ds[i] = d[i];
	}
	SPFA(t);
	int sp = ds[t];
//	std::cout << "\n";
//	for (int i = 0; i < n; i++) {
//		std::cout << d[i] << " ";
//	}
//	std::cout << "\n";
//	for (int i = 0; i < n; i++) {
//		std::cout << ds[i] << " ";
//	}
//	std::cout << "\n";
//	std::cout << sp << '\n';
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sp <= ds[i] + d[j] + 1 && sp <= ds[j] + d[i] + 1 && i != j && find(G[i].begin(), G[i].end(), j) == G[i].end()) {
//				std::cout << '\n' << i << " " << j << '\n';
//				std::cout << ds[i] << " " << ds[j] << '\n';
//				std::cout << d[i] << " " << d[j] << '\n';
				ans++;
			}
		}
	}
	if (ans)
		std::cout << ans/2;
	else {
		std::cout << 0;
	}
}