#include <iostream>
#include <algorithm>
#include <string>
#define ll int
#include <sstream>
#include <vector>

ll convert_from_string(const std::string &s) {    
	std::istringstream i(s);    
	ll x;    
	if(i >> x)    
		return x;    
	return 0.0;    
} 

int main(int argc, char *argv[]) {  
	ll n, k;
	std::string n_s;
	std::cin >> n_s;
	std::vector<int> aaa;
	n = convert_from_string(n_s);
	ll down = std::max(n-(ll)n_s.length()*9,0);
	int cnt = 0;
	for(ll i = down; i <= n; i++) {
		int temp = i, ans = i;
		while(temp) {
			ans += temp%10;
			temp /= 10;
		}
		if(ans == n) {
			cnt++;
			aaa.push_back(i);
		}
	}
	std::cout << cnt << '\n';
	for(int i = 0; i < cnt; i++) {
		std::cout << aaa[i] << '\n';
	}
	return 0;
}