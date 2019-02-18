#include <iostream>
#include <vector> 
#include <algorithm> 

const int maxn = 1e5+7;
const int maxm = 1e5+7;

class Kruskal { 
	struct UdEdge {
		int u, v, w;
		UdEdge(){}
		UdEdge(int u,int v,int w):u(u), v(v), w(w){}
	};
	int N, M;
	UdEdge pool[maxm]; 
	UdEdge *E[maxm]; 
	int P[maxn];
	int Find(int x){ 
		if(P[x] == x)
			return x;
		return P[x] = Find(P[x]);
	}	
	public:
	int s[maxn];
	static bool cmp(const UdEdge *a, const UdEdge *b) {
		return a->w < b->w; 
	}
	void Clear(int n) { 
		N = n;
		M = 0; 
	}
	void AddEdge(int u, int v, int w) {
		pool[M] = UdEdge(u, v, w);
		E[M] = &pool[M];
		++M; 
	}
	int Run(int k) {
		int i, ans = 0;
		for(i = 1; i <= N; ++i) 
			P[i] = i;
		std::sort(E, E+M, cmp); 
		for(i = 0; i < M; ++i) {
			UdEdge *e = E[i]; 
			int x = Find(e->u); 
			int y = Find(e->v); 
			if (x != y) {
				s[x] += s[y];
				P[y] = x;
				ans = std::max(e->w, ans); 
				if (s[x] >= k) return ans;
			}
		}
		return ans; 
	}
}xx;

int main(int argc, char *argv[]) {  
	int n, m, k, temp, u, v, w;
	std::cin >> n >> m >> k;
	xx.Clear(n);
	for (int i = 0; i < k; i++) {
		std::cin >> temp;
		xx.s[temp] = 1;
	}
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v >> w;
		xx.AddEdge(u, v, w);
	}
	int tot = xx.Run(k);
	for (int i = 0; i < k; i++) {
		std::cout << tot << " ";
	}
}