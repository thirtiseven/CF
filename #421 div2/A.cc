#include <iostream>
#define ll long long 


int main(int argc, char *argv[]) {  
	ll c, v0, v1, a, l;
	std::cin >> c >> v0 >> v1 >> a >> l;
	ll day = 0;
	ll r;
	ll now = c;
	while(now > 0) {
		if(v0 < v1) {
			r = v0;
		} else {
			r = v1;
		}
		if(now != c) {
			now += l;
		}
		now -= r;
		v0 += a;
		day++;
	}
	
	std::cout << day;
	return 0;
}