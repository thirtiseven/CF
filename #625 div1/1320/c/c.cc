#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
const int maxm = 1e6+7;

int n, m, p;
std::pair<int, int> a[maxn], b[maxn];
struct monster{
	int x, y, z;
}mo[maxn];
int sa[maxn], sb[maxn];

bool cmp(monster a, monster b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

int tree[maxm];
int maxx = 1e6;

void add(int i, int x) {
	for(;i <= maxx; i += i & -i)
		tree[i] += x;
}

int sum(int i) {
	int ret = 0;
	for(; i; i -= i & -i) ret += tree[i];
	return ret;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m >> p;
	int mina = 1e6, minb = 1e6;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
		mina = std::min(mina, a[i].second);
	}
	for (int i = 0; i < m; i++) {
		std::cin >> b[i].first >> b[i].second;
		minb = std::min(minb, b[i].second);
	}
	for (int i = 0; i < p; i++) {
		std::cin >> mo[i].x >> mo[i].y >> mo[i].z;
 	}
	std::sort(a, a+n);
	std::sort(b, b+n);
	sa[n-1] = a[n-1].second;
	for (int i = n-2; i >= 0; i--) {
		sa[i] = std::min(a[i].second, sa[i+1]);
	}
	sb[m-1] = b[m-1].second;
	for (int i = m-2; i >= 0; i--) {
		sb[i] = std::min(b[i].second, sb[i+1]);
	}
	std::sort(mo, mo+n, cmp);
	int ans = 0-mina-minb;
	for (int i = 0; i < p; i++) {
		add(mo[i].y, mo[i].z);
		if (a[n-1].first <= mo[i].x || b[m-1].first <= mo[i].y) {
			continue;
		}
		int cur = sum(mo[i].y);
		int xx = sa[std::lower_bound(a, a+n, std::make_pair(mo[i].x, -1))-a];
		int yy = sb[std::lower_bound(b, b+m, std::make_pair(mo[i].y, -1))-b];
//		std::cout << mo[i].x << ' ' << mo[i].y << ' ' << mo[i].z << '\n';
//		std::cout << xx << ' ' << yy << '\n';
//		std::cout << cur << '\n';
		cur -= xx;
		cur -= yy;
//		std::cout << cur << '\n';
		ans = std::max(cur, ans);
	}
	std::cout << ans << '\n';
}