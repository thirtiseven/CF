#include <iostream>
#include <algorithm>

#define ll long long int

int main(int argc, char *argv[]) {
	ll rgb[5];
	ll ans;
	for(int i = 0;i < 3;i++){
		std::cin >> rgb[i];
	}
	std::sort(rgb,rgb+3);
	if(rgb[2] > (rgb[0] + rgb[1]) * 2){
		ans = rgb[0] + rgb[1];
	} else {
		ans = (rgb[0] + rgb[1] + rgb[2])/3;
	}
	std::cout << ans << std::endl;
	return 0;
}