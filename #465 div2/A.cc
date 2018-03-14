#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (n%(n-i)==0) {
			cnt++;
		}
	}
	std::cout << cnt;
}