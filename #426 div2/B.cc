#include <iostream>
#include <cstring>
#define maxn 1000010

int main(int argc, char *argv[]) {  
	int n, k;
	int l[30], r[30], out[maxn];
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	char temp;
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		std::cin >> temp;
		out[i] = (int)(temp - 'A');
		if(!l[out[i]]) {
			l[out[i]] = i;
		}
		r[out[i]] = i;
	}
	int now = 0;
	for(int i = 1; i <= n; i++) {
		if(l[out[i]] == i) {
			now++;
		}
		if(now > k) {
			std::cout << "YES";
			return 0;
		}
		if(r[out[i]] == i) {
			now--;
		}
	}
	std::cout << "NO";
	return 0;
}