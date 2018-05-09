#include <iostream>
#include <algorithm>

const int maxn = 123456;
long long s[maxn], n, a, b;

int main(int argc, char *argv[]) {  
	std::cin >> n >> a >> b;
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
		sum += s[i];
	}
	long long S = s[0]*a/b;
	std::sort(s+1, s+n);
	int cnt = 0;
	while (sum > S) {
		sum -= s[n-1-cnt];
		cnt++;
	}
	std::cout << cnt;
}