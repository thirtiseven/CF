#include <iostream>
#include <algorithm>
#define maxn 110

int main(int argc, char *argv[]) { 
	int n, a[maxn];
	std::cin >> n; 
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	bool flag = true;  
	while(flag){  
		flag = false;  
		for(int i = 0; i < n - 1; i++)  {
			if(a[i] > a[i + 1]){  
				flag = true;  
				std::swap(a[i], a[i + 1]);  
				std::cout << i + 1 << ' ' << i + 2 << std::endl; 
			} 
		 }
	}  
	return 0;
}