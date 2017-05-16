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
			vk[i] = 'P';
			vk[i+1] = 'P';
		}
	}
	for(int i = 0;i < len-1; i++) {
		if(vk[i] == vk[i+1] && vk[i] != 'P') {
			cnt++;
			break;
		}
	}
	std::cout << cnt  << std::endl;
	//std::cout << std::max(cnt, cnt_change) << std::endl;
	return 0;
}