#include <iostream>
#include <string>
#include <algorithm>

std::string s;
int n, k;
int num[28];
int minn = 1e5+7;

int main(int argc, char *argv[]) {  
	std::fill(num, num+28, 0);
	std::cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		num[int(s[i]-'A')]++;
	}
	for (int i = 0; i < k; i++) {
		minn = std::min(num[i], minn);
	}
	std::cout << minn*k;
}