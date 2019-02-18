#include <iostream>
#include <vector> 
#include <algorithm> 

const int maxn = 4e5+7;
const int maxm = 4e5+7;
using ll = long long;

class Kruskal { 
	struct UdEdge {
		int u, v;
		ll w;
		UdEdge(){}
		UdEdge(int u,int v,ll w):u(u), v(v), w(w){}
	};
	int N, M;
	UdEdge pool[maxm]; 
	UdEdge E[maxm]; 
	int P[maxn];
	int Find(int x){ 
		if(P[x] == x)
			return x;
		return P[x] = Find(P[x]);
	}	
	public:
	static bool cmp(const UdEdge a, const UdEdge b) {
		return a.w < b.w; 
	}
	void Clear(int n) { 
		N = n;
		M = 0; 
	}
	void AddEdge(int u, int v, ll w) {
		pool[M] = UdEdge(u, v, w);
		E[M] = pool[M];
		++M; 
	}
	ll Run() {
		ll i, ans=0;
		for(i = 1; i <= N; ++i) 
			P[i] = i;
		std::sort(E, E+M, cmp); 
		for(i = 0; i < M; ++i) {
			UdEdge e = E[i]; 
			int x = Find(e.u); 
			int y = Find(e.v); 
			if(x != y) {
				P[y] = x;
				ans += e.w; 
			}
		}
		return ans; 
	}
};

Kruskal ac;

int main(int argc, char *argv[]) {  
	int n, m;
	ll a[maxn];
	ll minn = 1e13;
	int mini = 0;
	int u, v;
	ll w;
	std::cin >> n >> m;
	ac.Clear(n);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (a[i] < minn) {
			minn = a[i];
			mini = i;
		}
	}
	for (int i = 1; i <= n; i++) if (i != mini) {
		ac.AddEdge(mini, i, minn+a[i]);
	}
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v >> w;
		ac.AddEdge(u, v, w);
	}
	std::cout << ac.Run();
}