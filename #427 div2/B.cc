#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	std::string num;
	int k, a[100000], sum = 0;
	std::cin >> k >> num;
	for(int i = 0; i < num.length(); i++) {
		a[i] = num[i]-'0';
		sum += a[i];
	}
	std::sort(a,a+num.length());
	int ans = 0;
	while(sum < k) {
		sum += (9 - a[ans]);
		ans++;
	}
	std::cout << ans;
	return 0;
}