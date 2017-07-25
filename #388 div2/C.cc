#include <iostream>
#include <string>
#include <queue>
#define ll long long

int main(int argc, char *argv[]) {  
	ll n;
	std::string acm;
	std::queue<ll> dp, rp;
	std::cin >> n;
	std::cin >> acm;
	for(int i = 0; i < n; i++) {
		if(acm[i] == 'D') {
			dp.push(i);
		}
		if(acm[i] == 'R') {
			rp.push(i);
		}
	}
	while(dp.size() && rp.size()) {
		ll a = rp.front();
		ll b = dp.front();
		if(rp.front() < dp.front()){
			rp.pop();
			dp.pop();
			rp.push(n + 1 + a);
		} else {
			dp.pop();
			rp.pop();
			dp.push(n + 1 + b);
		}
	}
	if(rp.size() > 0) {
		std::cout << "R" << std::endl;
	} else {
		std::cout << "D" << std::endl;
	}
	return 0;
}