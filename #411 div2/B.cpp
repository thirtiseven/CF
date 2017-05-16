#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int that;
	while(n--) {
		that = n%4;
		if(that == 0 || that == 1){
			std::cout << "a";
		}else{
			std::cout << "b";
		}
	}
	std::cout << std::endl;
	return 0;
}