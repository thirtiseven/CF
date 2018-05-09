#include <iostream>
#include <algorithm>
const int maxn = 1234;
int n;
int a[maxn], b[maxn];
int main(int argc, char *argv[]) {  
	int tot = 0, ans = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
		tot -= a[i];
		tot += b[i];
		ans = std::max(ans, tot);
	}
	std::cout << ans;
}