#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {  
	int n, a, b;
	int t[200020];
	int cnt = 0;
	std::cin >> n >> a >> b;
	int c = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> t[i];
		if(t[i] == 1) {
			if(a > 0) {
				a--;
			} else if (b > 0) {
				b--;
				c++;
			} else if (c > 0) {
				c--;
			} else {
				cnt++;
			}
		} else {
			if(b > 0) {
				b --;
			} else {
				cnt += 2;
			}
		}
		//std::cout << cnt << "\n";
	}
	std::cout << cnt << "\n";
	return 0;
}