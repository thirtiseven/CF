#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {  
	char x[110], y[110];
	std::cin >> x;
	std::cin >> y;
	for(int i = 0;i < strlen(x);i++) {
		if (y[i] > x[i]) {  
			std::cout << "-1";  
			return 0; 
		}  
	}
	std::cout << y; 	  	
	return 0;
}