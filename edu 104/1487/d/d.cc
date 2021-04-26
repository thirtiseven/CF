#include <iostream>
#include <algorithm>
#include <cmath>

using ll = long long;

ll t, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		std::cout << int(floor(sqrt(2.0*double(n)-1.0))-1)/2 << '\n';
	}
}