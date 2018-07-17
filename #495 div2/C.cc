#include <iostream>
#include <cstring>
#include <set>

const int maxn = 1e6+7;

int main(int argc, char *argv[]) {  
	long long n;
	std::cin >> n;
	long long a[maxn], b[maxn];
	memset(b, 0, sizeof(b));
	std::set<int> s;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		b[a[i]] = s.size();
		s.insert(a[i]);
	}
	long long ans = 0;
	for (int i = 0; i < maxn; i++) {
		ans += b[i];
	}
	std::cout << ans;
}