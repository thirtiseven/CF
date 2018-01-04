#include <queue>
#include <iostream>

const long long inf = 100000000005;
typedef long long ll;
typedef std::pair<long long, int> PII;

int main(int argc, char *argv[]) {
	int n, num_of_edge, s, t;
	std::cin >> n >> num_of_edge;
	t = 0, s = n-1;
	std::vector<std::vector<PII> > edges(n);
	for(int i = 0; i < num_of_edge; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		edges[a-1].push_back(std::make_pair(c, b-1));
		edges[b-1].push_back(std::make_pair(c, a-1));
	}
	std::priority_queue<PII, std::vector<PII>, std::greater<PII> > q;
	std::vector<ll> dist(n, inf), dad(n, -1);
	q.push(std::make_pair(0, s));
	dist[s] = 0;
	while (!q.empty()) {
		PII p = q.top();
		q.pop();
		int here = p.second;
		if (here == t) break;
		if (dist[here] != p.first) continue;
		for (std::vector<PII>::iterator it = edges[here].begin(); it != edges[here].end(); it++) {
			if (dist[here] + it->first < dist[it->second]) {
				dist[it->second] = dist[here] + it->first;
				dad[it->second] = here;
				q.push(std::make_pair(dist[it->second], it->second));
			}
		}
	}
	if (dist[0] == inf) {
		std::cout << "-1\n";
		return 0;
	}
	if (dist[t] < inf) {
		for (int i = t; i != -1; i = dad[i]) {
			std::cout << i+1 << (i == s ? '\n' : ' ');
		}
	}
	return 0;
}