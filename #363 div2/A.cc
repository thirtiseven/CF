#include <iostream>
#include <string>

#define maxn 200010

int main(int argc, char *argv[]) {  
	int n, ans, f = 0, fir = 0;
	std::string lr;
	int a[maxn];
	std::cin >> n >> lr;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(i && lr[i] == 'L' && lr[i - 1] == 'R') {  
			if(!fir) ans = (a[i] - a[i - 1] + 1) / 2, fir = 1; //第一次出现  
			else  
				ans = std::min(ans,(a[i] - a[i - 1] + 1) / 2);  //取最优  
			f = 1;  
		} 
	}
	if(f) {
		std::cout << ans << "\n";
	} else {
		std::cout << "-1\n";
	}
	return 0;
}