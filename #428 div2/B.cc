#include <iostream>
#include <algorithm>

#define maxn 10010

int main(int argc, char *argv[]) {  
	int n, k;
	std::cin >> n >> k;
	int two = 2 * n, four = n;
	int a[maxn];
	for(int i = 0; i < k; i++) {
		std::cin >> a[i];
		while(a[i] >= 4 && four > 0) {
			a[i] -= 4;
			four--;
		}
	}
	for(int i = 0; i < k; i++) {
		if(a[i] == 3 && four > 0) {
			a[i] -= 3;
			four--;
		}
	}
	for(int i = 0; i < k; i++) {
		while(a[i] >= 2 && two > 0) {
			a[i] -= 2;
			two--;
		}
	}
	for(int i = 0; i < k; i++) {
		while(a[i] == 1 && two > 0) {
			a[i] -= 1;
			two--;
		}
	}
	int twoman4 = 0, oneman4 = 0;
	for(int i = 0; i < k; i++) {
		while(a[i] == 2 && four > 0) {
			a[i] -= 2;
			four--;
			twoman4++;
		}
	}
	for(int i = 0; i < k; i++) {
		while(a[i] == 1 && four > 0) {
			a[i] --;
			oneman4++;
		}
	}
	for(int i = 0; i < k; i++) {
		while(a[i] == 1 && twoman4 > 0) {
			a[i] --;
			twoman4--;
		}
	}
	for(int i = 0; i < k; i++) {
		while(a[i] == 2 && oneman4 > 0) {
			a[i] --;
			oneman4--;
		}
	}
	for(int i = 0; i < k; i++) {
		while(a[i] == 1 && oneman4 > 0) {
			a[i] --;
			oneman4--;
		}
	}
	bool flag = 1;
	for(int i = 0; i < k; i++) {
		if(a[i]) {
			flag = 0;
		}
	}
	if(flag) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}