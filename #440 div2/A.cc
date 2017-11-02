#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, m, temp;
	int num[11];
	memset(num, 0, sizeof(num));
	int min1 = 10, min2 = 10;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> temp;
		if(temp < min1) {
			min1 = temp;
		}
		num[temp]++;
	}
	for(int i = 0; i < m; i++) {
		std::cin >> temp;
		if(temp < min2) {
			min2 = temp;
		}
		num[temp]++;
	}
	for(int i = 1; i < 10; i++) {
		if(num[i] > 1) {
			std::cout << i;
			return 0;
		}
	}
	if(min1 > min2) {
		std::swap(min1, min2);
	}
	std::cout << min1 << min2;
	return 0;
}