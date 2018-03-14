#include <iostream>
#include <algorithm>

using ll = long long;
ll n,k,a,b;

ll dp(ll x) {
	if(x<k || k==1) {
		return (x-1)*a;
	}
	if(x % k != 0){
		return dp(x - x%k) + x%k * a;
	}
	return dp(x/k) + std::min(b,a*(x-x/k));
}

int main(int argc, char* argv[]) {
	std::cin>>n>>k>>a>>b;
	std::cout<<dp(n);
}