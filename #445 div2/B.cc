#include <iostream>
#include <set>
#include <cstring>

#define maxn 200009

int main(int argc, char *argv[]) {  
	int n, a[maxn], num[maxn];
	memset(num, 0, sizeof(num));
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		num[a[i]]++;
	}
	for(int i = 0; i < n; i++) {
		num[a[i]]--;
		if(num[a[i]] <= 0) {
			std::cout << a[i] << std::endl;
			break;
		}
	}
	return 0;
}