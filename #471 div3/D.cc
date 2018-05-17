#include <iostream>
#include <map>

const int maxn = 100009;

int main(int argc, char *argv[]) {  
	long long n, b[maxn], c[maxn];
	std::map<int, int> aa;
	std::cin >> n;
	std::cin >> b[0];
	long long  minn = 1000000009, maxx = -1000000009;
	for (int i = 1; i < n; i++) {
		std::cin >> b[i];
		c[i-1] = b[i] - b[i-1];
		minn = std::min(minn, c[i-1]);
		maxx = std::max(maxx, c[i-1]); 
	}
	bool yes = 1;
	long long ans = 10000000000000;
	for (int i = minn; i <= maxx; i++) {
		
	}
}