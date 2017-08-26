#include <iostream>  
#include <algorithm>  
  
int main(int argc, char *argv[]) {  
	int n, b, d;  
	int a[100005]; 
	std::cin >> n >> b >> d; 
	for(int i = 0; i < n; i++) {  
		std::cin >> a[i];
	}  
	int ans=0, sum=0;  
	for(int i = 0; i < n; i++) {  
		if(a[i] > b) {
			continue; 
		} else {
			sum+=a[i];  
		}
		if(sum>d) {
			ans++;
			sum=0;  
		}	
	}  
	std::cout << ans << std::endl;
	return 0;  
}  