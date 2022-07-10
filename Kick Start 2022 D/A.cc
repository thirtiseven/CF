#include <iostream>
#include <algorithm>

const int maxn = 1e4+7;

int T;
int n, m, a[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		double sum = 0;
		if ((n-m+1)%2==1) {
			sum = a[(n-m+1)/2];
		} else {
			sum = (a[(n-m+1)/2] + a[(n-m+1)/2-1]) / 2.0;
		}
		for (int i = n-m+1; i < n; i++) {
			sum += a[i];
		}
		std::cout << "Case #" << CAS << ": " << sum << '\n';
 	}
}