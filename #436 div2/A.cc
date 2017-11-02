#include <iostream>
#include <algorithm>
#include <cstring>

#define maxn 110

struct number {
	int id;
	int size;
} card[maxn];

bool cmp(number a, number b){
	return a.size < b.size;
}

int main(int argc, char *argv[]) {  
	int n, num[maxn];
	std::cin >> n;
	for(int i = 0; i < maxn; i++) {
		card[i].size = 0;
		num[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> card[i].id;
		num[card[i].id]++;
	}
	for(int i = 0; i < n; i++) {
		card[i].size = num[card[i].id];
	}
	std::sort(card, card+n, cmp);
	bool flag = 0;
	int alice, bob;
	for(int i = 1; i < 101; i++) {
		if(card[i].size != 0 && card[i].size == card[i-1].size && card[i].id != card[i-1].id && card[i].size + card[i-1].size == n	) {
			flag = 1;
			alice = card[i-1].id;
			bob = card[i].id;
			break;
		}
	}
	if(flag) {
		std::cout << "YES\n" << alice << " " << bob << "\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}