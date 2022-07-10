#include <iostream>
#include <algorithm>
#include <vector>

using ll = int;
const int maxn = 1e5+7;

int T;
ll n, l, p[maxn], d[maxn];
ll recent0[maxn], recent1[maxn];

struct ant{
	int id, p, d;
} ants[maxn];

bool cmp(ant &a, ant &b) {
	return a.p < b.p;
}

std::vector<std::pair<ll, ll>> timef; // time, id

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		timef.clear();
		std::cin >> n >> l;
		for (int i = 0; i < n; i++) {
			std::cin >> p[i] >> d[i];
			ants[i].id = i;
			ants[i].p = p[i];
			ants[i].d = d[i];
		}
		std::sort(ants, ants+n, cmp);
		int last = -1;
		for (int i = n-1; i >= 0; i--) {
			recent0[i] = last;
			if (ants[i].d == 0) {
				last = i;
			}
		}
		last = -1;
		for (int i = 0; i < n; i++) {
			recent1[i] = last;
			if (ants[i].d == 1) {
				last = i;
			}
		}
		for (int i = 0; i < n; i++) {
//			std::cerr << ants[i].id << ' ';
			ll x;
			if (ants[i].d == 0) {
				if (recent1[i] == -1) {
					x = ants[i].p;
				} else {
					if (recent0[recent1[i]] == -1) {
						x = l - ants[recent1[i]].p;
//						x = ants[recent0[i]].p;
					} else {
						x = ants[recent0[i]].p;
//						x = l - ants[recent1[i]].p;
					}
				}
			} else {
				if (recent0[i] == -1) {
					x = l - ants[i].p;
				} else {
					x = ants[recent0[i]].p;
					if (recent1[recent0[i]] == -1) {
						x = ants[recent0[i]].p;
//						x = l - ants[recent1[i]].p;
					} else {
						x = l - ants[recent1[i]].p;
//						x = ants[recent0[i]].p;
					}
				}
			}
			timef.push_back(std::make_pair(x, ants[i].id+1));
		}
//		std::cerr << '\n';
		std::sort(timef.begin(), timef.end());
		std::cout << "Case #" << cas << ": ";
		for (auto it: timef) {
			std::cout << it.second << ' ';
		}
		std::cout << '\n';
	}
}