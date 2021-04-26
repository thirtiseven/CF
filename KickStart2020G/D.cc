#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using ld = long double;
using ll = long long;

const int maxn = 10;

int T, n, temp;
std::vector<ll> a;
ld ans = 0;

void gao(std::vector<ll> x, ld cur) {
	ld siz = (long double)(x.size()-1);
	for (int i = 0; i < x.size()-1; i++) {
		ans += (ld)(x[i] + x[i+1])/siz/cur;
		std::vector<ll> xx;
		for (int j = 0; j < i; j++) {
			xx.push_back(x[j]);
		}
		xx.push_back(x[i]+x[i+1]);
		for (int j = i+2; j < x.size(); j++) {
			xx.push_back(x[j]);
		}
		gao(xx, cur*(xx.size()));
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		a.clear();
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> temp;
			a.push_back(temp);
		}
		ans = 0;
		gao(a, 1.0);
		std::cout << "Case #" << CAS << ": " << std::fixed << std::setprecision(13) << ans << '\n';
	}
}