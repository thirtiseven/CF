#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define maxn 110

int main(int argc, char *argv[]) {  
	int n, k;
	std::string s;
	int len[maxn];
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> s;
		len[i] = s.length();
	}
	std::cin >> s;
	int passlen = s.length();
	std::sort(len, len + n);
	int mintry = 0, maxtry = 0;
	for(int i = 0; i < n; i++) {
		if(len[i] < passlen) {
			mintry++;
		}
		if(len[i] <= passlen) {
			maxtry++;
		}
		if(len[i] > passlen) {
			break;
		}
	}
	mintry++;
	maxtry += ((maxtry-1)/k)*5;
	mintry += ((mintry-1)/k)*5;
	std::cout << mintry << " " << maxtry << std::endl;
	return 0;
}