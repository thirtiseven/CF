#include <iostream>

int n, temp;
int a[100020];
int max = -1, cnt = 0;

int main(int argc, char *argv[]) { 
	std::cin >> n;
	for(int i = 0; i < 2*n; i++) {
		std::cin >> temp;
		a[temp]++;
		if(a[temp]==1) {
			cnt++;
		} else if(a[temp] == 2) {
			cnt--;
		}
		if(cnt > max) {
			max = cnt;
		}
	}
	std::cout << max <<std::endl;
	return 0;
}