#include <iostream>
#include <string>  
#include <algorithm>   

int main(int argc, char *argv[]) {
	int n, xr, yr, xb, yb;  
	std::string s;  
	std::cin >> n >> s;
	xr = yr = xb = yb = 0;  
	for(int j = 0; j < n; j++) {  
		if(j % 2) { 
			if(s[j] == 'r') xr++;  
			else    xb++;  
		} else {  
			if(s[j] == 'r') yr++;  
			else    yb++;  
		}  
	}  
  
	int ans = std::min(std::max(xr, yb), std::max(xb, yr));  
	std::cout << ans;
	return 0;  
} 