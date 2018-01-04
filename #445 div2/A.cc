#include <iostream>

int main(int argc, char *argv[]) {  
	int a[7], sum = 0;
	for(int i = 0; i < 6; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	if(sum % 2 == 1) {
		std::cout << "NO\n";
		return 0;
	} else {
		int val = sum/2;
		bool flag = 0;
		for(int i = 0; i < 4; i++) {
			for(int j = i+1; j < 5; j++) {
				for(int k = j+1; k < 6; k++) {
					if(a[i] + a[j] + a[k] == val) {
						flag = 1;
						break;
					}
				}
			}
		}
		std::cout << ((flag)?("YES\n"):("NO\n"));
	}
	return 0;
}