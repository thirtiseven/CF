#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	int a[200005];  
	std::cin >> n; 
	int flag = 1;  
	for(int i=0;i<n;i++) {
		std::cin >> a[i];
	}
	for(int i=0;i<n;i++) {  
		if(a[i] & 1) {  
			a[i]--;  
			a[i+1]--;  
			if(a[i+1] < 0 || i == n-1) {
				printf("NO\n");
				return 0;
			}  
		}  
	}  
	if(flag)  
	std::cout << "YES" << std::endl;
	return 0;  
}