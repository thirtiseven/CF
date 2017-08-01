#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		for(int i = 2; i < a; i++) {
			if((a%i) == 0) {
				if(log(b)/log(i*i) == (int)log(b)/log(i*i)) {
					if()
					std::cout << "Yes";
					flag = 1;
				}
				break;
			}
		}
		if()
	}
	return 0;
}