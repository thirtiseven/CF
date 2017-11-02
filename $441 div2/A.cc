#include <iostream>

int main(int argc, char *argv[]) {  
	int n, a, b, c, ans;
	std::cin >> n >> a >> b >> c;
	int minn = std::min(a, std::min(b, c));
	if(a == minn) {
		ans = (n-1) * a;
	} else if(b == minn){
		ans = (n-1) * b;
	} else {
		ans = std::min(a, b) + (n-2) * minn;
	}
	if(n < 2) {
		ans = 0;
	}
	std::cout << ans << std::endl;
	return 0;
}