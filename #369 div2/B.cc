#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long

int main(int argc, char *argv[]) {  
	ll n;
	std::cin >> n;
	if(n == 1) {
		std::cout << "1";
		return 0;
	}
	ll sq[505][505];
	ll zpx, zpy;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> sq[i][j];
			if(sq[i][j] == 0) {
				zpx = i;
				zpy = j;
			}
		}
	}
	ll sum = 0, sumz = 0, sumt = 0;
	for(int i = 0; i < n; i++) {
		sum += sq[std::abs(zpx-1)][i];
	}
	for(int i = 0; i < n; i++) {
		sumz += sq[zpx][i];
	}
	sq[zpx][zpy] = sum - sumz;
	bool flag = 1;
	for(int i = 0; i < n; i++) {
		sumt += sq[i][i];
	}
	if(sumt != sum) {
		flag = 0;
	}
	sumt = 0;
	for(int i = 0; i < n; i++) {
		sumt += sq[n-i-1][i];
	}
	if(sumt != sum) {
		flag = 0;
	}
	for(int i = 0; i < n; i++) {
		sumt = 0;
		for(int j = 0; j < n; j++) {
			sumt += sq[i][j];
		}
		if(sumt != sum) {
			flag = 0;
			break;
		}
	}
	for(int j = 0; j < n; j++) {
		if(!flag) {
			break;
		}
		sumt = 0;
		for(int i = 0; i < n; i++) {
			sumt += sq[i][j];
		}
		if(sumt != sum) {
			flag = 0;
		}
	}
	if(sq[zpx][zpy] <= 0) {
		flag = 0;
	}
	if(flag) {
		std::cout << sq[zpx][zpy];
	} else {
		std::cout << "-1\n";
	}
	return 0;
}