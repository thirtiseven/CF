#include <iostream>
#include <cstring>
#include <algorithm>


bool cmpo(char a, char b) {
	return a < b;
}

bool cmpi(char a, char b) {
	return a > b;
}

int main(int argc, char *argv[]) {  
	char oleg[300010];
	char igor[300010];
	char answ[300010];
	int cnt = 1,cnto = 1,cnti = 1;
	std::cin >> oleg >> igor;
	int len = strlen(oleg);
	for(int i = 0;i < len;i++) {
		answ[i] = '6';
	}
	std::sort(oleg,oleg+len,cmpo);
	std::sort(igor,igor+len,cmpi);
	//std::cout << oleg << " " << igor;
	/*
	for(int i = 0; i < len; i++){
		if(i%2==0) {
			std::cout << oleg[(i+1)/2];
		} else {
			std::cout << igor[(i)/2];
		}
	}
	*/
	for(int i = 0; i < len; i++){
		if(i%2==0) {
			if(oleg[(i+1)/2] < igor[len/2]) {
				answ[len-cnt] = oleg[len/2-cnto];
				cnt++;
				cnto++;
			} else {
				answ[i-cnt] = oleg[(i+1)/2];
			}
		} else {
			if(igor[(i+1)/2] > oleg[len/2]) {
				answ[i-cnt] = igor[len/2-cnti];
				cnti++;
			} else {
				answ[i-cnt] = oleg[i/2];
			}
		}
		for(int i = 0;i < len;i++) {
			std::cout << answ[i];
		}
		std::cout << "\n";
	}
	for(int i = 0;i < len;i++) {
		std::cout << answ[i];
	}
	std::cout << "\n";
	return 0;
}