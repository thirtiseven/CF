#include <iostream>
#include <set>
#include <vector>

const int maxn = 2e5+7;
using ll = long long;

ll a[maxn];
int n;
ll sum = 0;
std::multiset<ll> s; 
std::vector<int> ans;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
		s.insert(a[i]);
	}
	for (int i = 0; i < n; i++) {
		if ((sum-a[i])%2==0 && (s.count((sum-a[i])/2) > 1 || (s.count((sum-a[i])/2) > 0 && sum != a[i]*3))) {
			ans.push_back(i);
		} 
	}
	std::cout << ans.size() <<'\n';
	for (auto it: ans) {
		std::cout << it+1 << ' ';
	}
}