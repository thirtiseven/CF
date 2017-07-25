#include <iostream>
#include <cmath>
#include <cstring>

#define ll long long

ll n, pp, id, left = 0, right = 0;
ll p[1000020], when[1000020];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	memset(when, 0, sizeof(when));
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> p[i];
		pp += std::abs(p[i]-i);
		when[(p[i] - i + n) % n]++;
		if(p[i] > i) {
			left++;
		} else {
			right++;
		}
	}
	ll ans = pp, index = 0;
	for(int i = 1; i < n; i++) {
		pp -= left;
		pp += right - 1;
		pp += p[(n-i)%n+1] - n + p[(n-i)%n+1] - 1;
		left -= when[i] - 1;
		right += when[i] - 1;
		if(pp < ans) {
			ans = pp;
			index = i;
		}
	}	
	std::cout << ans <<  " " <<index;
	return 0;
}