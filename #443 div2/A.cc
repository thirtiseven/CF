#include <iostream>
#define maxn 1100

int main(int argc, char *argv[]) {  
	int n, s[maxn], d[maxn];
	int now = 0;
	std::cin >> n;
	std::cin >> s[0] >> d[0];
	now = s[0];
	for(int i = 1; i < n; i++) {
		std::cin >> s[i] >> d[i];
		while(s[i] <= now) {
			s[i] += d[i];
		}
		now = s[i];
	}
	std::cout << now << std::endl;
	return 0;
}