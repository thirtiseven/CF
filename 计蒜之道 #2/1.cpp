#include <iostream>
#include <cstring>
#include <algorithm>

int wood[55];

int main() {  
	memset(wood, 0, 56);
	int n[5], k, d;
	std::cin >> n[1] >> n[2] >> n[3] >> n[4];
	std::cin >> k >> d;
	int num[5];
	num[1] = 0;
	num[4] = n[1];
	num[3] = num[4] + n[4];
	num[2] = num[3] + n[3];
	if(k == 1){
		wood[d-1] = 1;
		wood[d] = 1;
	}
	if(k == 4) {
		wood[d-1+num[4]] = 1;
		wood[d+num[4]] = 1;
	}
	if(k == 3) {
		wood[d-1+num[3]] = 1;
		wood[d+num[3]] = 1;
	}
	if(k == 2) {
		wood[d-1+num[2]] = 1;
		wood[d+num[2]] = 1;
	}
	
/*	for(int i = 0; i < 54; i++){
		std::cout << wood[i] << " ";
	}*/
//	std::cout << std::endl;
	int cnt = 0;
	for(int i = 1; i <= 6;i++) {
		for(int j = i; j <= 6; j++) {
			int select = (i + j - 1) % 4 + 1;
			int start;
			start = std::min(i, j) + num[select] - 1;
			if((wood[(start + 1)%54]&&wood[(start + 2)%54])||(wood[(start + 9)%54]&&wood[(start + 10)%54])||(wood[(start + 17)%54]&&wood[(start + 18)%54])) {
				cnt++;
			}
		}
	}
	std::cout << cnt << std::endl;
	return 0;
}