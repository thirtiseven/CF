#include <iostream>
#include <vector> 
#include <queue>
#include <cstring>

using ll = long long;
const ll inf = 1e18;
const int maxn = 3e5+7;

class Dijkstra{ 
private:
	struct HeapNode{ 
		int u;
		ll d;
		HeapNode(int u, ll d) :u(u), d(d){}
		bool operator < (const HeapNode &b) const{
			return d > b.d; 
		}
	};
	struct Edge{ 
		int v;
		ll w;
		int id;
		Edge(int v, ll w, int id) :v(v), w(w), id(id){}
	}; 
	std::vector<Edge> G[maxn];
	bool vis[maxn];
public:
	std::vector<std::pair<int, int>> tree[maxn];
	int mat[maxn];
	int cnt = 0;
	int k;
	ll d[maxn];
	void clear(int n){
		int i;
		for(i=0;i<n;++i) 
			G[i].clear(); 
		for(i=0;i<n;++i) 
			d[i] = inf;
		memset(vis, 0, sizeof(vis)); 
		memset(mat, 0, sizeof(mat)); 
	}
	void AddEdge(int u, int v, int w, int id){ 
		G[u].push_back(Edge(v, w, id));
		G[v].push_back(Edge(u, w, id));
	}
	void Run(int s){ 
		int u;
		std::priority_queue<HeapNode> q;
		d[s] = 0; 
		q.push(HeapNode(s, 0)); 
		while (!q.empty()) {
			u = q.top().u;
			q.pop();
			if (!vis[u]){
				vis[u] = 1;
				for (std::vector<Edge>::iterator e = G[u].begin(); e != G[u].end(); ++e)
					if (d[e->v] > d[u] + e->w){ 
						d[e->v] = d[u] + e->w;
						tree[u].push_back(std::make_pair(e->v, e->id));
						tree[e->v].push_back(std::make_pair(u, e->id));
						q.push(HeapNode(e->v, d[e->v])); 
					}
			}
		}
	}
	
	void dfs(int cur, int fa) {
		if (cnt >= k) {
			return;
		}
		if (vis[cur]) return;
		vis[cur] = 1;
		for (auto it: tree[cur]) {
			if (it.first != fa && mat[it.second] == 0) {
				if (cnt >= k) {
					return;
				}
				mat[it.second] = 1;
				cnt++;
				if (cnt >= k) {
					return;
				}
				dfs(it.first, cur);
			}
		}
	}
	
	void gao(int s, int kk) {
		k = kk;
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		dfs(s, 0);
	}
};

Dijkstra dd;

int main(int argc, char *argv[]) {  
	int n, m, k;
	std::cin >> n >> m >> k;
	dd.clear(n+1);
	int u, v;
	ll w;
	for (int i = 1; i <= m; i++) {
		std::cin >> u >> v >> w;
		dd.AddEdge(u, v, w, i);
	}
	dd.Run(1);
	if (k < n-1) {
		dd.gao(1, k);
		std::cout << k << '\n';
		for (int i = 1; i <= m; i++) {
			if (dd.mat[i]) {
				std::cout << i << " ";
			}
		}
		std::cout << '\n';
	} else {
		dd.gao(1, n-1);
		std::cout << n-1 << '\n';
		int tot = 0;
		for (int i = 1; i <= m; i++) {
			if (dd.mat[i]) {
				std::cout << i << " ";
			}
		}
	}
}