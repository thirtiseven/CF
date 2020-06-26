#include <iostream>

int x, bit[7], xx[7], ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> x;
	int cnt = 6;
	while (x) {
		bit[cnt] = x%2;
		x/=2;
		cnt--;
	}
//	for (int i = 1; i <= 6; i++) {
//		std::cerr << bit[i] << " \n"[i==6];
//	}
	xx[1] = bit[1];
	xx[5] = bit[5];
	xx[6] = bit[2];
	xx[4] = bit[3];
	xx[3] = bit[4];
	xx[2] = bit[6];
//	for (int i = 1; i <= 6; i++) {
//		std::cerr << xx[i] << " \n"[i==6];
//	}
	ans = 0;
	cnt = 1;
	for (int i = 6; i >= 1; i--) {
		ans += xx[i]*cnt;
		cnt *= 2;
	}
	std::cout << ans << '\n';
}