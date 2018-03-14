#include <iostream>

int main(int argc, char *argv[]) { 
	int ans[1000008];
	for (int i = 1; i < 1e6; i++) {
		int tot = 1;
		int dig = i;
		while (tot > 10) {
			tot = 1;
			while(dig) {
				tot *= (dig)%10;
				dig /= 10;
			}
			dig = tot;
		}
		ans[i] = tot;
	}
	for (int i = 0; i < 20; i++) {
		std::cout << ans[i] << " ";
	}
}