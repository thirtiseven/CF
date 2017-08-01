#include <iostream>
#include <algorithm>
#include <cmath>
#define maxn 200010
#define ll long long

ll n, m, k, x, s;
ll a[maxn], b[maxn], c[maxn], d[maxn];

void input_data() {
	std::cin >> n >> m >> k >> x >> s;
	for(int i = 1; i <= m; i ++) {
		std::cin >> a[i];
	}
	for(int i = 1; i <= m; i ++) {
		std::cin >> b[i];
	}
	for(int i = 1; i <= k; i ++) {
		std::cin >> c[i];
	}
	for(int i = 1; i <= k; i ++) {
		std::cin >> d[i];
	}
}

int main(int argc, char *argv[]) {  
	input_data();
	ll ans = n * x;  
	a[0] = x;   
	for(int i = 0; i <= m; i++) {  
		if(b[i] <= s) { 
			ans = std::min(ans, (n - c[std::upper_bound(d + 1, d + k + 1, s - b[i]) - d - 1]) * a[i]);
		}  
	}  
	std::cout << ans << std::endl;
	return 0;
}