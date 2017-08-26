#include <iostream>
#include <cstring>
#define maxn 100010

int main(int argc, char *argv[]) {  
	int n, a[maxn], b[maxn];
	memset(a, 0, sizeof(a));
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		b[i] = a[i] + a[i+1];
		std::cout << b[i] << " ";
	}
	return 0;
}