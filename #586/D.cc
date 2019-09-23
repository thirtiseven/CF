#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

using ll = long long;

std::set<ll> s;
std::map<ll, int> mp;
std::vector<ll> v, ans;
int n;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	ll x, maxx = 0;
	for (ll i = 0; i < n; i++) {
		std::cin >> x;
		s.insert(x);
		v.push_back(x);
		maxx = std::max(maxx, x);
	}
	std::sort(v.begin(), v.end());
	for (ll i = v.size()-1; i >= 0; i--) {
		for (auto it: s) {
			if (it + v[i] > maxx) {
				break;
			}
			if (s.count(it+v[i])) {
				if (mp[v[i]] == 0 && mp[it+v[i]] == 0) {
					mp[v[i]] = 1;
					mp[it+v[i]] = 2;
				} else if (mp[v[i]] == 0) {
					mp[v[i]] = 3 - mp[it+v[i]];
				} else if (mp[it+v[i]] == 0) {
					mp[it+v[i]] = 3 - mp[v[i]];
				} else {
					s.erase(v[i]);
					ans.push_back(v[i]);
				}
			}
		}
	}
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << it << ' ';
	}
}