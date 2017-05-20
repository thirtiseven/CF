#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

struct friends {
	double c;
	double s;
}a[60010];

int n;
double minn, maxn;

double maxt(double point) {
	double temp, max_time = 0;
	for (int i = 0; i < n; i++){
		temp = fabs(point - a[i].c) / a[i].s;
		if(temp > max_time) {
			max_time = temp;
		}
	}
	return max_time;
}

double solve() {
	double left = 0.0, right = 10e9;
	while(fabs(right - left) > 1e-7) {
		double fir = left + (right - left)/3.0;
		double sec = left + (right - left)/3.0*2.0;
		if(maxt(fir) < maxt(sec)) {
			right = sec;
		} else {
			left = fir;
		}
	}
	return maxt(left);
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].c;
	}
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].s;
	}
	std::cout << std::fixed << std::setprecision(12) << solve() << std::endl;
	return 0;
}