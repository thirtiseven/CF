#include <iostream>
#include <algorithm>
#include <vector>

using ll = int;

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::vector<std::pair<int, int> > ans;
	ll n, m;
	std::cin >> n >> m;
	if (m < n-1) {
		std::cout << "Impossible\n";
		exit(0);
	}
	int now = 0;
	m-=(n-1);
	if (m == 0) {
		std::cout << "Possible\n";
		for (int i = 2; i <= n; i++) {
			std::cout << i << " 1\n";
		}
		exit(0);
	}
	for (int i = 2; i < n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (gcd(i, j)==1) {
				now++;
				ans.push_back(std::make_pair(i, j));
				if (now >= m) {
					goto out;
				}
			}
		}
	}
	if (now < m) {
		std::cout << "Impossible\n";
		exit(0);
	}
	out:;
	std::cout << "Possible\n";
	for (int i = 2; i <= n; i++) {
		std::cout << i << " 1\n";
	}
	for (auto it: ans) {
		std::cout << it.first << " " << it.second << '\n';
	}
}