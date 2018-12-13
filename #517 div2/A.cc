#include <iostream>

int main(int argc, char *argv[]) {  
	int w, h, k;
	std::cin >> w >> h >> k;
	int aa = 1;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += (w-aa)*2+(h-aa)*2;
		aa+=4;
	}
	std::cout << ans << '\n';
}