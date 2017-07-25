#include <iostream>

int main(int argc, char *argv[]) {  
	long long n, m, k;//the number of hobbits, the number of pillows and the number of Frodo's bed.
	std::cin >> n >> m >> k;
	if(n == 1) {
		std::cout << m << std::endl;
		return 0;
	}
	m -= n;
	long long dis_l = k - 1, dis_r = n - k;
	long long ans = 1;
	while(1) {
		if(m <= 0) {
			break;
		}
		ans++;
		if(ans - 2 <= dis_l) {
			m -= (ans - 1);
		} else {
			m -= dis_l;
		}
		if(ans - 2 <= dis_r) {
			m -= (ans - 1);
		} else {
			m -= dis_r;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}