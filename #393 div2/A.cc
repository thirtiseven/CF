#include <iostream>

int main(int argc, char *argv[]) {  
	int m, d;
	std::cin >> m >> d;
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int num = days[m];
	int ans = 0;
	num -= (8 - d);
	ans++;
	ans += (num - 1) / 7 + 1;
	std::cout << ans << std::endl;
	return 0;
}