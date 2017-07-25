#include <iostream>
#include <algorithm>
#define ll long long

int main(int argc, char *argv[]) {  
	int t;
	std::cin >> t;
	while(t--) {
		ll x, y, p, q;
		std::cin >> x >> y >> p >> q;
		if(p==q) {  
			if(x==y) {  
				std::cout << "0";
			} else {
				std::cout << "-1";
			} 
			continue;  
		}  
		if(p==0) {  
			if(x==y) {  
				std::cout << "0";
			} else {
				std::cout << "-1";
			} 
			continue;  
		}  
		ll mayben[4] = {1, !(x%p)?(x/p):(x/p+1), !(y%q)?(y/q):(y/q+1), !((y-x)%(q-p))?((y-x)/(q-p)):((y-x)/(q-p)+1)};
		std::sort(mayben,mayben+4);
		ll n = mayben[3];
		std::cout << n * q - y << std::endl;
	}
	return 0;
}