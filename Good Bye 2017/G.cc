#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

long long convert_from_string(long long x) {  
	std::ostringstream o; 
	std::string s;   
	if(o << x)    
		s = o.str(); 
	std::sort(s.begin(), s.end());
	std::istringstream i(s);    
	long long y;    
	if(i >> y)    
		return y;       
} 

int main(int argc, char *argv[]) {  
//	std::string x;
//	std::cin >> x;
	long long x;
	long long ans;
	long long mod = 1e9+7;
	std::cin >> x;
	for(int i = 1; i < x; i++) {
		ans += convert_from_string(x);
//		std::cout << ans;
		ans = ans%mod;
	}
	std::cout << ans;
	return 0;
}