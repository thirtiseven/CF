#include <iostream>
#include <algorithm>
#include <set>

const int maxn = 1e5+7;
using ll = long long;

struct food{
	ll id, a, c;
	food (ll _id = 0, ll _a = 0, ll _c = 0) {
		id = _id;
		a = _a;
		c = _c;
	}
	bool operator < (const food &b) const {
		if (this->c == b.c) {
			return this->id < b.id;
		}
		return this->c < b.c;
	}
};

std::set<food> s;
ll aa[maxn], cc[maxn];

int main(int argc, char *argv[]) {  
	ll n, m, now = 0;
	std::cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		std::cin >> aa[i];
		now += aa[i];
	}
	for (ll i = 1; i <= n; i++) {
		std::cin >> cc[i];
	}
	for (ll i = 1; i <= n; i++) {
		s.insert(food(i, aa[i], cc[i]));
	}
	ll ans = 0;
	bool empty = 0;
	ll t, d;
	for (ll i = 1; i <= m; i++) {
		ans = 0;
		std::cin >> t >> d;
		if (now < d || empty == 1) {
			empty = 1;
		} else {
			auto it = s.find(food(t, aa[t], cc[t]));
			if (it != s.end()) {
				if (aa[t] > d) {
					s.erase(it);
					aa[t] -= d;
					now -= d;
					ans += cc[t]*d;
					s.insert(food(t, aa[t], cc[t]));
				} else {
					s.erase(it);
					ans += cc[t] * aa[t];
					d -= aa[t];
					now -= aa[t];
					aa[t] = 0;
					while (d > 0 && !s.empty()) {
						auto it2 = s.begin();
						if (it2->a > d) {
							ll bbb = it2->id;
							s.erase(it2);
							ans += d*cc[bbb];
							aa[bbb] -= d;
							now -= d;
							d = 0;
							s.insert(food(bbb, aa[bbb], cc[bbb]));
						} else {
							ans += aa[it2->id] * cc[it2->id];
							now -= aa[it2->id];
							d -= it2->a;
							aa[it2->id] = 0;
							s.erase(it2);
						}
					}
				}
			} else {
				while (d > 0 && !s.empty()) {
					auto it3 = s.begin();
					if (it3->a > d) {
						ll aaa = it3->id;
						s.erase(it3);
						ans += d*cc[aaa];
						aa[aaa] -= d;
						now -= d;
						d = 0;
						s.insert(food(aaa, aa[aaa], it3->c));
					} else {
						ans += aa[it3->id] * cc[it3->id];
						now -= aa[it3->id];
						d -= it3->a;
						aa[it3->id] = 0;
						s.erase(it3);
					}
				}
			}
		}
		if (empty) {
			std::cout << "0\n";
		} else {
			std::cout << ans << '\n';
		}
	}
}

/*
8 5
8 6 2 1 4 5 7 5
6 3 3 2 6 2 3 2
2 8
1 4
4 7
3 4
6 10

6 6
6 6 6 6 6 6
6 66 666 6666 66666 666666
1 6
2 6
3 6
4 6
5 6
6 66

6 6
6 6 6 6 6 6
6 66 666 6666 66666 666666
1 6
2 13
3 6
4 11
5 6
6 6
*/