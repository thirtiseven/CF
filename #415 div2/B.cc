#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

#define maxn 100100

int main(int argc, char *argv[]) {  
	long long n, f, ans;
	long long k[maxn], l[maxn], b[maxn];
	memset(b, 0, sizeof(b));
	std::cin >> n >> f;
	for(int i = 0; i < n; i++) {
		std::cin >> k[i] >> l[i];
		ans += std::min(k[i], l[i]);
		if (k[i] < l[i]) {
			b[i] = std::min(k[i],l[i]-k[i]);
		}
	}
	std::sort(b, b+n);
	std::reverse(b, b+n);
	for(int i = 0; i < f; i++) {
		ans += b[i];
	}
	std::cout << ans << std::endl;
	return 0;
}