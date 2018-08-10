#include <map>
#include <iostream>
#include <algorithm>

const int maxn = 1e7+7;

std::pair<int,int> a[maxn];
int n, i, u, v, d, mx, ans, f[maxn];
int main(int argc, char *argv[]) {
	std::map<int, int> mp;
	std::map<int, int>::iterator it;
	std::cin >> n;
	for(i=0; i<n; i++) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	std::sort(a, a+n);
	ans = a[0].first+1;
	mp[0] = n-1;
	f[n-1] = 1;
	mx = d = 0;
	for(i = n; i--; ) {
		it = mp.upper_bound(a[i].second);
		it--;
		u = (it->first), v = (it->second);
		mp.erase(it);
		f[v-u]--;
		d -= (!f[v-u]);
		if(u!=a[i].second) {
			mp[u] = a[i].second-1;
			d += (!f[a[i].second-1-u]);
			f[a[i].second-1-u]++;
		}
		if(v!=a[i].second) {
			mp[a[i].second+1] = v;
			d += (!f[v-a[i].second-1]);
			f[v-a[i].second-1]++;
		}
		if(!d) {
			if(mx<=mp.size()) {
				mx = mp.size();
				ans = a[i-1].first+1;
			}
		}
	}
	std::cout << ans;
}