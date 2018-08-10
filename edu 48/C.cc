#include <iostream>
#include <algorithm>

const int maxn = 6e5+7;

using ll = long long;

ll a[maxn], s1[maxn], sm[maxn], s2[maxn], ss[maxn];

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	std::cin >> a[0];
	s1[0] = a[0];
	sm[0] = 0;
	s2[0] = 0;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		std::cin >> a[i];
		s1[i] = s1[i-1] + a[i];
		sm[i] = sm[i-1] + i*a[i];
	}
	std::cin >> a[n];
	for (int i = n+1; i < n+n; i++) {
		std::cin >> a[i];
	}
	s2[n] = cnt*a[n];
	cnt++;
	for (int i = 1; i < n; i++) {
		if (i%2) {
			s2[n+i] = s2[n+i-1] + cnt*a[n+i];
			cnt++;
			s2[i] = s2[n+i] + cnt*a[i];
			cnt++;
		} else {
			s2[i] = s2[i-1] + cnt*a[i];
			cnt++;
			s2[n+i] = s2[i] + cnt*a[n+i];
			cnt++;
		}
	}
	s1[2*n-1] = s1[n-1] + a[2*n-1];
	sm[2*n-1] = sm[n-1] + n*a[2*n-1];
	for (int i = 2*n-2; i >= n; i--) {
		s1[i] = s1[i+1] + a[i];
		sm[i] = sm[i+1] + (3*n-i-1)*a[i];
	}
	cnt = 1;
	ss[n] = 0;
	for (int i = n+1; i < 2*n; i++) {
		ss[i] = ss[i-1] + cnt*a[i];
		cnt++;
	}
	ss[n-1] = ss[2*n-1] + cnt*a[n-1];
	cnt++;
	for (int i = n-2; i >= 0; i--) {
		ss[i] = ss[i+1] + cnt*a[i];
		cnt++;
	}
	ll ans = sm[n];
	for (int i = 1; i < n; i+=2) {
		ans = std::max(ans, s2[i] + (i+1)*(s1[i+n+1] - s1[i]) + sm[i+n+1] - sm[i]);
	}
	for (int i = n; i < 2*n; i+=2) {
		ans = std::max(ans, s2[i] + (i-n+1)*(s1[i+1] - s1[i-n]) + ss[i+1-n] - ss[i]);
	}
	std::cout << ans << '\n';
}