#include <iostream>

int main(int argc, char *argv[]) {  
	int a[7];
	for (int i = 1; i <= 6; i++) std::cin >> a[i];
	int ans = 0;
	int cnt = 0;
	int now = 2*a[1]-1;
	while (cnt < a[2] && cnt < a[6]) {
		now += 2;
		ans += now;
		cnt ++;
	}
	now ++;
	while (cnt < a[2] || cnt < a[6]) {
		ans += now;
		cnt ++;
	}
	now --;
	while (cnt < a[2] + a[3]) {
		ans += now;
		now -= 2;
		cnt ++;
	}
	std::cout << ans << '\n';
}