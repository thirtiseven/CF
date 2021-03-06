#include <iostream>
#include <vector>
#include <queue>

const int MAXE = 1e6+7;
const int MAXN = 2e5+7;
const int INF = 1000000;
const int maxn = 1e6+7;
int flag[maxn], primes[maxn], totPrimes, primeid[maxn];

void euler_sieve(int n) {
	totPrimes = 0;
	memset(flag, 0, sizeof(flag));
	flag[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes[totPrimes++] = i;
		}
		for (int j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = 1;
			if (i % primes[j] == 0)
			break;
		}
	}
}

using ii = std::pair<int, int>;

struct edge { 
	int u, v, cost, cap, flow; 
} E[MAXE], * pred[MAXN];

std::vector<edge *> g[MAXN];
int N, M, EE, dist[MAXN], phi[MAXN];

inline edge * opp(edge * e) { 
	return E + ((e - E) ^ 1); 
}

void inti() {
	for (int i = 0; i <= N; i++) {
		g[i].clear();
	}
	EE = 0;
}

void add_edge(int u, int v, int cost, int cap) {
	E[EE] = { u, v, cost, cap, 0 };
	g[u].emplace_back(E + (EE++));
	E[EE] = { v, u, -cost, 0, 0 };
	g[v].emplace_back(E + (EE++));
}

bool dijkstra(int S, int T) {
	std::fill(dist, dist + N, INF);
	std::fill(pred, pred + N, nullptr);
	std::priority_queue<ii, std::vector<ii>, std::greater<ii>> pq;
	dist[S] = 0;
	for (pq.emplace(dist[S], S); !pq.empty(); ) {
		int u = pq.top().second; 
		pq.pop();
		for (auto e : g[u]) {
			if (e->cap - e->flow > 0 && dist[e->v] > dist[e->u] + e->cost + phi[e->u] - phi[e->v]) {
				dist[e->v] = dist[e->u] + e->cost + phi[e->u] - phi[e->v];
				pred[e->v] = e;
				pq.emplace(dist[e->v], e->v);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		phi[i] = std::min(INF, phi[i] + dist[i]);
	}
	return dist[T] != INF;
}

std::pair<int, int> mincost_maxflow(int S, int T) {
	int mincost = 0, maxflow = 0;
	std::fill(phi, phi + N, 0);
	while (dijkstra(S, T)) {
		int flow = INF;
		for (edge * e = pred[T]; e; e = pred[e->u])
			flow = std::min(flow, e->cap - e->flow);
		for (edge * e = pred[T]; e; e = pred[e->u]) {
			mincost += e->cost * flow;
			e->flow += flow;
			opp(e)->flow -= flow;
		}
		maxflow += flow;
	}
	return std::make_pair(mincost, maxflow);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	euler_sieve(1000001);
	for (int i = 0; i < totPrimes; i++) {
		primeid[primes[i]] = i+1;
	}
	
}