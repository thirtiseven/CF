#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int a[1010], b[1010];
	int rate = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
		if(a[i]!=b[i]) {
			rate = 1;
		}
	}
	if(!rate) {
		for(int i = 0; i < n-1; i++) {
			if(a[i] < a[i+1]) {
				rate = -1;
			}
		}
	}
	switch (rate) {
		case  1: std::cout << "rated\n";   break;
		case  0: std::cout << "maybe\n";   break;
		case -1: std::cout << "unrated\n"; break;
	}
	return 0;
}