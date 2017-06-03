#include <iostream>
#include <algorithm>
#include <iomanip>

int main(int argc, char *argv[]) {  
	int n;
	double w, v, u;
	std::cin >> n >> w >> v >> u;
	double max_time = 0;
	double x[10010], y[10010];
	for(int i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
		if(x[i]/v+(w-y[i])/u > max_time) {
			max_time = x[i]/v+(w-y[i])/u;
		}
	}
	for(int i = 0; i < n; i++) {
		if(x[i]/v > y[i]/u) {
			break;
		}
		if(i==n-1) {
			std::cout << std::fixed << std::setprecision(7) << (w/u) << std::endl;
			return 0;
		}
	}
	for(int i = 0; i < n; i++) {
		if(x[i]/v < y[i]/u) {
			break;
		}
		if(i==n-1) {
			std::cout << std::fixed << std::setprecision(7) << (w/u) << std::endl;
			return 0;
		}
	}
	//std::cout << max_time << std::endl;
	std::cout << std::fixed << std::setprecision(7) << max_time << std::endl;
	return 0;
}