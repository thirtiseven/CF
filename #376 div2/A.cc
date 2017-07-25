#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) {    
	char a[105];  
	std::cin >> a; 
	int len = std::strlen(a);  
	char p='a';  
	int ans=0;  
	for(int i=0;a[i];i++) {  
		int t = std::abs(a[i]-p);  
		ans += std::min(t,26-t);  
		p=a[i];  
	}  
	std::cout << ans << std::endl;  		
	return 0;
}