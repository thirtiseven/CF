#include <iostream>

#define maxn 1234

int main(int argc, char *argv[]) {  
	int n, a[maxn];
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1; i < n-1; i++) {
		if(a[i] < a[i-1] && a[i] < a[i+1]) {
			cnt++;
		} else if(a[i] > a[i-1] && a[i] > a[i+1]) {
			cnt++;
		}
	}
	std::cout << cnt << std::endl;
	return 0;
}