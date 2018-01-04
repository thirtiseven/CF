#include <iostream>

const int maxn = 2e5+9;

int main(int argc, char *argv[]) {  
	int h, a[maxn];
	std::cin >> h;
	for(int i = 0; i <= h; i++) {
		std::cin >> a[i];
	}
	bool flag = 1;
	int label = 0;
	for(int i = 1; i <= h; i++) {
		if(a[i] > 1) {
			if(a[i-1] > 1) {
				flag = 0;
				label = i;
			}
		}
	}
//	std::cout << label << std::endl;
	if(flag) {
		std::cout << "perfect\n";
	} else {
		std::cout << "ambiguous\n";
		int cnt = 0, las = cnt;
		for(int i = 0; i <= h; i++) {
			las = cnt;
			for(int j = 0; j < a[i]; j++) {
				std::cout << las << " ";
				cnt++;
			}
		}
		std::cout << '\n';
		cnt = 0, las = cnt;
		for(int i = 0; i <= h; i++) {
			las = cnt;
			for(int j = 0; j < a[i]; j++) {
				if(i == label && j==0) {
					std::cout << las-1 << " ";
				} else {
					std::cout << las << " ";
				}
				cnt++;
			}
		}
	}
	return 0;
}