#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string a, b;
	std::cin >> a;
	bool flag = 0;
	for(int i = 0; i < a.length(); i++) {
		if(!flag && a[i] != 'a') {
			flag = 1;
		}
		if(flag) {
			if(a[i] == 'a') {
				flag = 0;
				break;
			}
			a[i]--;
		}
		if(i == a.length() - 1 && !flag) {
			a[i] = 'z';
		}
	}
	std::cout << a;
	return 0;
}