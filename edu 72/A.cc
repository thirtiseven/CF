#include <iostream>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		int maxx = a+c;
		if (a+c <= b) {
			std::cout << "0\n";
			continue;
		}
		int minn = (a+b+c+2)/2;
	 	minn = std::max(minn, a);
		std::cout << maxx-minn+1 << '\n';
	}
}