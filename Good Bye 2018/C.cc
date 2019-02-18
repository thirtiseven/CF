#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

std::vector<ll> s;

int main(int argc, char *argv[]) {  
	ll n;
	std::cin >> n;
	ll i;
	for (i = 1LL; i*i < n; i++) {
		if (n%i==0) {
			s.push_back(i);
			s.push_back(n/i);
		}
	}
	if (i*i==n) s.push_back(i);
	std::sort(s.begin(), s.end());
	std::reverse(s.begin(), s.end());
	for (auto it: s) {
		std::cout << (n/it)*(2+n-it)/2 << ' ';
	}
}