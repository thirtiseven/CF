#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) {  
	char vk[110];
	std::cin >> vk;
	int len = strlen(vk);
	int flag = 1;
	int cnt = 0, cnt_change = 0;
	for(int i = 0;i < len-1; i++) {
		if(vk[i] == 'V' && vk[i+1] == 'K') {
			cnt++;
		}
	}
	for(int i = 0;i < len-2; i++) {
		if(vk[i] == 'V' && vk[i+1] == 'V' && vk[i+2] == 'V') {
			cnt++;
			flag = 0;
			break;
		}
		if(vk[i] == 'K' && vk[i+1] == 'K' && vk[i+2] == 'K') {
			flag = 0;
			cnt++;
			break;
		}
	}
	for(int i = len-2;i < len-1; i++) {
		if(vk[i] == 'V' && vk[i+1] == 'V'&&flag) {
			flag = 0;
			cnt++;
			break;
		}
	}
	for(int i = 0;i < 2; i++) {
		if(vk[i] == 'K' && vk[i+1] == 'K'&&flag) {
			flag = 0;
			cnt++;
			break;
		}
	}
	
	/*
	for(int i = 0;i < len-1; i++) {
		if(vk[i] == vk[i+1]) {
			cnt++;
			break;
		}
	}*/
	
	/*
	for(int i = 0;i < len-1;) {
		if(vk[i] == 'V' && vk[i+1] == 'K') {
			cnt_change++;
			i += 2;
		} else if(vk[i] == 'V' && vk[i+1] == 'V' && flag) {
			cnt_change++;
			i+=2;
			vk[i+1] = 'K';
			flag = 0;
		} else if(vk[i] == 'K' && vk[i+1] == 'K' && flag) {
			cnt_change++;
			i+=2;
			vk[i] = 'V';
			flag = 0;
		} else {
			i++;
		}
	}
	*/
	
	std::cout << cnt  << std::endl;
	//std::cout << std::max(cnt, cnt_change) << std::endl;
	return 0;
}