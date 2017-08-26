#include <iostream>  
#include <string>  
   
int main(int argc, char *argv[]) {  
	int n, d, ans = 0, tmp = 0;  
	std::cin >> n >> d;
	for(int i = 0; i < d; ++i) {  
		std::string str;
		std::cin >> str; 
		bool flag = false;  
		for(int j = 0; j < n; ++j) {  
			if(str[j] == '0') {  
				flag = true;  
				break;  
			}  
		}  
		if(flag) {  
			tmp ++;  
		} else {  
			tmp = 0;  
		}  
		if(tmp > ans) {
			ans = tmp;  
		}
	}  
	std::cout << ans; 
	return 0;  
}  