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
	}
	std::sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); i++) {
		if (s.count(v[i]-v[i-1])) {
			s.erase(v[i]-v[i-1]);
			ans.push_back(v[i]-v[i-1]);
		}
	}
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << it << ' ';
	}
}