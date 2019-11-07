#include <iostream>
#include <algorithm>

const int maxn = 50000+8;

using ll = long long;

struct point {
	ll x, y, z, id;
};

point ze;

ll dis(point a, point b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}

bool cmp(point a, point b) {
	if (dis(ze, a) == dis(ze, b)) {
		if (a.y == b.y) {
			return a.z < b.z;
		}
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	}
	return dis(ze, a) < dis(ze, b);
}

point p[maxn];

int main(int argc, char *argv[]) {  
	ze.x = -1e8, ze.y = -1e8, ze.z = -1e8, ze.id = -1;
	ll n;
	std::cin >> n;
	for (ll i = 0; i < n; i++) {
		std::cin >> p[i].x >> p[i].y >> p[i].z;
		p[i].id = i+1;
	}
	std::sort(p, p+n, cmp);
	for (ll i = 0; i < n/2; i++) {
		std::cout << p[i*2].id << ' ' << p[i*2+1].id << '\n';
	}
}