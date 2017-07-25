#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	double n, a;
	std::cin >> n >> a;
	double degree;
	double part = 360.0 / n;
	double least = 400;
	int parts1 = 0, parts2 = 0;
	bool flag = 1;
	for(int i = 1; i <= n/2; i++) {
		if(fabs((i * part) / 2.0 - a) < least) {
			least = fabs((i * part) / 2 - a);
			parts1 = i;
			flag = 1;
		}
		if((fabs(180 - ((i * part) / 2) - a) < least) && i != 1) {
			least = fabs(180 - ((i * part) / 2) - a);
			parts2 = i;
			flag = 0;
		}
	}
	if(flag) {	
		std::cout << "1 " << n << " " << 1+parts1 << std::endl; 
	} else {
		std::cout << "1 2 " << 1+parts2 << std::endl;
	}
	return 0;
}