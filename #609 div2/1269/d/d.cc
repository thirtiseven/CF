#include <iostream>
#include <algorithm>

const int maxn = 300003;

long long a[maxn];
long long n;

int main(int argc, char *argv[]) {  
	long long black = 0, white = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (i%2==0) {
			black += a[i]/2ll;
			white += a[i]-a[i]/2ll;
		} else {
			black += a[i]-a[i]/2ll;
			white += a[i]/2ll;
		}
	}
	std::cout << std::min(black, white) << '\n';
}