#include <iostream>

int main(int argc, char *argv[]) {  
	int a, b, c, num, temp;
	int pos[100010];
	std::cin >> a >> b >> c;
	std::cin >> num;
	int cnt = 0;
	for(int i = 0;i < num; i++) {
		std::cin >> temp;
		if(temp > b && temp < c) {
			cnt++;
		}
	}
	std::cout << cnt << std::endl;
	return 0;
}