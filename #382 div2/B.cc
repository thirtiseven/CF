#include <iostream>
#include <algorithm>
#include <iomanip>
#define maxn 100010
#define ll long long

int main(int argc, char *argv[]) {  
	ll n, n1, n2, a[maxn];
	std::cin >> n >> n1 >> n2;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}	
	std::sort(a, a+n);
	std::reverse(a, a+n);
	if(n1 > n2) {
		std::swap(n1, n2);
	}
	ll sum1 = 0, sum2 = 0;
	for(int i = 0; i < n1; i++) {
		sum1 += a[i];
	}
	for(int i = n1; i < n2 + n1; i++) {
		sum2 += a[i];
	}
	double ans = ((double)sum1/(double)n1) + ((double)sum2/(double)n2);
	std::cout << std::fixed << std::setprecision(7) << ans << std::endl;
	return 0;
}