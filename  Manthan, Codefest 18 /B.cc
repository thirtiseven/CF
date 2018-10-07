#include <iostream>
#include <algorithm>
int n, s, a[200000];
int main(int argc, char *argv[]){
	std::cin >> n >> s;
	for(int i=0; i<n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	long long ans = 0;
	for (int i=0; i<=n/2; i++) {
		ans += std::max(0, a[i]-s);
	}
	for (int i=n/2; i<n; i++) {
		ans += std::max(0, s-a[i]);
	}
	std::cout << ans;
}