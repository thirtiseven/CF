#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int seg = floor(sqrt(n));
	int cnt = 0;
	for (int i = 0; i < n/seg; i++) {
		for (int j = seg; j >= 1; j--) {
			std::cout << i*seg+j << " ";
			cnt++;
		}
	}
	for (int i = n; i >= cnt+1; i--) {
		std::cout << i << " ";
	}
}