#include <iostream>

int main(int argc, char *argv[]) {  
	int n, s;
	std::cin >> n >> s;
	int h[123], m[123];
	h[0] = 0, m[0] = 0;
	std::cin >> h[1] >> m[1];
	if ((h[1]-h[0])*60+m[1]-m[0] >= s+1) {
		std::cout << "0 0\n";
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		std::cin >> h[i] >> m[i];
		int sa = (h[i]-h[i-1])*60+m[i]-m[i-1];
		if (sa >= 2*s+3) {
			std::cout << h[i-1] + (m[i]+s+1)/60 << " " << (m[i-1]+s+1)%60 << '\n';
			return 0;
		}
	}
	std::cout << h[n] + (m[n]+s+1)/60 << " " << (m[n]+s+1)%60 << '\n';
}