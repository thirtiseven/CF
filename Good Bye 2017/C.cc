#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;  
	double r, y[maxn], x[maxn];
	for(int i = 0; i < 1009; i++) {
		y[i] = 0;
	}
	std::cin >> n >> r;
	for(int i = 0; i < n; i++) {
		std::cin >> x[i];
//		double maxx = 0;
//		int maxl = x[i];
		double ans = 0;
		for(int j = std::max(1, int(x[i]-2*r)); j <= std::min(1000, int(x[i]+2*r)); j++) {
			if(y[j] == 0) {
				ans = std::max(ans, r);
			} else {
				ans = std::max(ans, y[j] + std::sqrt(double(2*r)*double(2*r) - double(std::abs(x[i]-j))*double(std::abs(x[i]-j))));
			}
//			std::cout << ans << '\n';
		}
		y[int(x[i])] = ans;
//		if(maxx == 0) {
//			y[int(x[i])] = r;
//		} else {
//			y[int(x[i])] = maxx + sqrt(double(2*r)*double(2*r) - double(std::abs(x[i]-maxl))*double(std::abs(x[i]-maxl)));
//		}
		std::cout << std::fixed << std::setprecision(15) << y[int(x[i])] << " ";
	}
//	for(int i = 0; i < n; i++) {
//		std::cout << std::fixed << std::setprecision(8)  << y[int(x[i])] << " ";
//	}
	return 0;
}