#include <iostream>
#include <iomanip>

const double eps = 1e-10;

int main(int argc, char *argv[]) {  
	int T; 
	double x;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf", &x);
		if (x == 0) { 
			std::cout << "Y 0 0\n";
		} else if (x <= 3) {
			std::cout << "N\n";
		} else {
			std::cout << "Y ";
			double l = 1, r = 2, mid, a = x-1, b = 1, tem;
			for (int i = 0; i < 100; i++) {
				mid = (l+r)/2;
				tem = x - mid;
				if (tem * mid - x <= eps) l = mid;
				else r = mid;
			}
			std::cout << std::fixed << std::setprecision(12) << l << " " << x-l << '\n';
		}
	}
}