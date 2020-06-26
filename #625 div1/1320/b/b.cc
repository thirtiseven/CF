#include <iostream>
#include <vector> 
#include <queue>
#include <cstring>

#define INF 0x7FFFFFFF 
const int maxn = 2e5+7;
using namespace std;

class Dijkstra{ 
private:
	struct HeapNode{ 
		int u;
		int d;
		HeapNode(int u, int d) :u(u), d(d){}
		bool operator < (const HeapNode &b) const{
			return d > b.d; 
		}
	};
	struct Edge{ 
		int v;
		int w; 
		Edge(int v, int w) :v(v), w(w){}
	}; 
	vector<Edge>G[maxn];
	bool vis[maxn];
public:
	int d[maxn];
	int fa[maxn];
	int sum[maxn];
	void clear(int n){
		int i;
		for(i=0;i<n;++i) 
			G[i].clear(); 
		for(i=0;i<n;++i) 
			d[i] = INF, fa[i] = -1, sum[i] = 0;
		memset(vis, 0, sizeof(vis)); 
	}
	void AddEdge(int u, int v, int w){ 
		G[u].push_back(Edge(v, w));
	}
	void Run(int s){ 
		int u;
		priority_queue<HeapNode> q;
		d[s] = 0; 
		sum[s] = 1;
		q.push(HeapNode(s, 0)); 
		while (!q.empty()){
			u = q.top().u;
			q.pop();
			if (!vis[u]){
				vis[u] = 1;
				for (vector<Edge>::iterator e = G[u].begin(); e != G[u].end(); ++e)
					if (d[e->v] > d[u] + e->w){ 
						fa[e->v] = u;
						sum[e->v] = 0;
						d[e->v] = d[u] + e->w;
						q.push(HeapNode(e->v, d[e->v])); 
					} else if (d[e->v] == d[u] + e->w) {
						sum[e->v] = 1;
					}
			}
		}
	}
}DD;

int n, m, k, u, v;
int p[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	DD.clear(n);
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v;
		DD.AddEdge(v-1, u-1, 1);
	}
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		std::cin >> p[i];
		p[i]--;
	}
	DD.Run(p[k-1]);
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < k-1; i++) {
//		std::cout << p[i]+1 << ' ' <<  DD.fa[p[i]] << ' ';
//		std::cout << DD.d[p[i+1]] << ' ' << DD.d[DD.fa[p[i]]] << '\n';
		if (DD.d[p[i+1]] != DD.d[DD.fa[p[i]]]) {
			ans1++;
			ans2++;
		} else {
			if (DD.sum[p[i]] == 1) {
				ans2++;
			}
		}
	}
	std::cout << ans1 << ' ' << ans2 << '\n';
}