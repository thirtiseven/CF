#include <iostream>

bool tshirt(int s, int p) {
	int i = (s / 50) % 475;
	for(int j = 0; j < 25; j++) {
		i = (i * 96 + 42) % 475;
		if(26 + i == p) {
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	int p, x, y, cnt = 0, tx;
	std::cin >> p >> x >> y;
	while(x < y) {
		x += 100;
		cnt++;
	}
	tx = x;
	while(tx >= y) {
		if(tshirt(tx, p)) {
			std::cout << cnt;
			return 0;
		}
		tx -= 50;
	}
	while(!tshirt(x, p)) {
		cnt++;
		x += 50;
		if(tshirt(x, p)) {
			break;
		}
		x += 50;
	}
	std::cout << cnt;
	return 0;
}