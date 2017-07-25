#include <iostream>

int main(int argc, char *argv[]) {  
	double n, m, k;//the number of hobbits, the number of pillows and the number of Frodo's bed.
	std::cin >> n >> m >> k;
	m -= n;
	if(m == 0) {
		std::cout << "1\n";
		return 0;
	}
	double l = k - 1, r = n - k;
	double ans = (m + (r * r + r + l * l + l)/2) / n;
	int a = (int)(ans) + 1;
	std::cout << ans<< std::endl;
	return 0;
}