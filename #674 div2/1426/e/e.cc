#include <iostream>
#include <algorithm>

int n, a[4], b[4];

#include <queue> 
#include <vector> 
#include <cstring> 
#include <algorithm>

const int maxn = 10;
const int inf = 0x7FFFFFFF; 

struct Edge { 
	int c, f;
	unsigned v, flip;
	Edge(unsigned v, int c, int f, unsigned flip) : v(v), c(c), f(f), flip(flip) {} 
};

/*
*b:BFS使用 ，
*a:可改进量 ， 不会出现负数可改进量。
*p[v]:u到v的反向边，即v到u的边。*cur[u]:i开始搜索的位置 ，此位置前所有路已满载。*s:源点。
*t:汇点 。
*/

class Dinic { 
private:
	bool b[maxn];
	int a[maxn];
	unsigned p[maxn], cur[maxn], d[maxn];
	std::vector<Edge> G[maxn];
public:
	unsigned s, t;
	void Init(unsigned n) { 
		for(int i=0; i<=n; ++i)
			G[i].clear();
	}
	void AddEdge(unsigned u, unsigned v, int c) { 
		G[u].push_back(Edge(v, c, 0, G[v].size())); 
		G[v].push_back(Edge(u, 0, 0, G[u].size()-1)); //使用无向图时将0改为c即可
	}
	bool BFS() { 
		unsigned u, v;
		std::queue<unsigned> q; 
		memset(b, 0, sizeof(b)); 
		q.push(s);
		d[s] = 0;
		b[s] = 1; 
		while (!q.empty()) {
			u = q.front();
			q.pop();
			for (auto it = G[u].begin(); it != G[u].end(); ++it) {
				Edge &e = *it; 
				if(!b[e.v] && e.c > e.f){
					b[e.v] = 1; 
					d[e.v] = d[u] + 1; 
					q.push(e.v);
				} 
			}
		}
		return b[t]; 
	}
	int DFS(unsigned u, int a){ 
		if(u==t || a==0)
			return a; 
		int flow = 0, f;
		for (unsigned &i = cur[u]; i<G[u].size(); ++i){ 
			Edge &e = G[u][i];
			if (d[u]+1 == d[e.v] && (f = DFS(e.v, std::min(a, e.c - e.f))) > 0) { 
				a -= f;
				e.f += f; 
				G[e.v][e.flip].f -= f; 
				flow += f;
				if (!a) break;
			} 
		}
		return flow; 
	}
	int MaxFlow(unsigned s, unsigned t){ 
		int flow = 0;
		this->s = s; 
		this->t = t; 
		while (BFS()) {
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, inf); 
		}
		return flow; 
	}
};

Dinic gao;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3];
	int maxx = 0, minn = 0;
	maxx += (std::min(a[1], b[2]) + std::min(a[2], b[3]) + std::min(a[3], b[1]));
	gao.Init(8);
	for (int i = 1; i <= 3; i++) {
		gao.AddEdge(7, i, a[i]);
		gao.AddEdge(i+3, 8, b[i]);
	}
	gao.AddEdge(1, 4, inf);
	gao.AddEdge(1, 6, inf);
	gao.AddEdge(2, 4, inf);
	gao.AddEdge(2, 5, inf);
	gao.AddEdge(3, 5, inf);
	gao.AddEdge(3, 6, inf);
	int res = gao.MaxFlow(7, 8);
	minn = n - res;
	std::cout << minn << ' ' << maxx << '\n';
}