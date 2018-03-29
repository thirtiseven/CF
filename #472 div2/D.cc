#include <iostream>
#include <algorithm>
#include <cmath>

const long long maxn = 1e5+9;

int main(int argc, char *argv[]) {  
	long long n, m[maxn], d[maxn], s[maxn];
	long long tot = 0, maxx = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> m[i];
		m[i]++;
	}
	s[n-1] = m[n-1];
	for (int i = n-2; i >= 0; i--) s[i] = std::max(s[i+1]-1, m[i]);
	tot = s[0];
	for (int i = 1; i < n; i++) {
		if (s[i] < s[i-1]) {
			s[i] = s[i-1];
		}
		tot += s[i];
	}
	for (int i = 0; i < n; i++) tot -= m[i];
	std::cout << tot;
}