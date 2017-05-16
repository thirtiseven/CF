#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdio>

int n;
double p;
long long sum;
struct device{
	double a, b;
}N[100010];

double a[100010], b[100010];

double test(double mid) {
	double power = mid * p;
	double temp = 0;
	for(int i = 0; i < n;i++) {
		temp = mid * a[i] - b[i];
		if(temp > 0) {
			power -= temp;
		}
		if(power < 0){
			return 0;
		}
	}		
	return 1;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> p;
	for(int i = 0;i < n;i++) {
		scanf("%lf %lf",&a[i],&b[i]);
		sum += a[i];
	}
	if(sum <= p) {
		std::cout << "-1" << std::endl;
		return 0;
	}
	double begin = 0.0, end = 1e18, mid;
	while(1) {
		mid = (begin + end) / 2.0;
		if(fabs(begin - end) < 1e-5) {
			std::cout << std::fixed << std::setprecision(10) <<mid << std::endl;
			break;
		}
		if(test(mid)) {
			begin = mid;
		} else {
			end = mid;
		}
	}
	return 0;
}