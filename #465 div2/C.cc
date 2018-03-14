#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char *argv[]) {  
	double R, x1, x2, y1, y2;
	std::cin >> R >> x1 >> y1 >> x2 >> y2;
	double dis = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
//	std::cout << dis <<  std::endl;
	if (dis > R) {
		std::cout << std::fixed << std::setprecision(16) << x1 << " " << y1 << " " << R << std::endl;
	} else if (dis == 0) {
		std::cout << std::fixed << std::setprecision(16) << x2-(R/2) << " " << y1 << " " << R/2 << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(16) <<
		x1 + (x1 - x2) * (R - dis) / 2 / dis << " " <<
		y1 + (y1 - y2) * (R - dis) / 2 / dis << " " <<
		(dis + R) / 2 << std::endl;
	}
}