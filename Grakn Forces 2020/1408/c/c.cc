#include <iostream>
#include <algorithm>
#include <iomanip>

const int maxn = 1e5+7;
const double eps = 1e-8;

int t, n;
double l, a[maxn];

double gao1(double x) {
	double res = 0;
	for (int i = 1; i <= n+1; i++) {
		if (a[i] <= x) {
			res += (a[i]-a[i-1])/double(i);
		} else {
			res += (x - a[i-1])/double(i);
			break;
		}
	}
	return res;
}

double gao2(double x) {
	double res = 0;
	for (int i = n; i >= 0; i--) {
		if (a[i] >= x) {
			res += (a[i+1] - a[i])/double(n-i+1);
		} else {
			res += (a[i+1] - x)/double(n-i+1);
			break;
		}
	}
	return res;	
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> l;
		a[0] = 0, a[n+1] = l;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		double left = 0, right = l, mid;
		for (int i = 0; i < 100; i++) {
			mid = (left+right)/2.0;
			if (gao1(mid) > gao2(mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		std::cout << std::fixed << std::setprecision(15) << gao2(mid) << '\n';
	}
}