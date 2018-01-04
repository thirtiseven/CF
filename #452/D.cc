#include <iostream>
#define ll int

int main(int argc, char *argv[]) {  
	ll n;
	std::cin >> n;
	int cnt = 1, miao = n, endd = n%10;
	while(miao>10) {
		miao/=10;
		cnt++;
	}
	if(n < 5) {
		std::cout << "0\n";
		return 0;
	}
	int fff;
	for(fff = 5; fff < n; fff *= 10);
	//std::cout << miao << " " << cnt << " " << fff << '\n';
	int ans;
	if(n < 20) {
		ans = n-4-(n+1)/10;
	} else if(miao >= 5) {
		ans = std::min(2*fff-2, n)-fff+1;
	} else {
		ans = n-4 + std::min(2*fff-2, n)-fff+1;
	}
	std::cout << ans << '\n';
	return 0;
}