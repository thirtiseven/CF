#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int cnt = n;
	for (int i = 0; (1 << i) <= n; i++) {
		if (cnt == 3) {
			printf("%d %d %d\n",(1 << i),(1 << i),(1 << i) * (n / (1 << i)));
			return 0;
		}
		int cnt1 = cnt - (n / (1 << (i + 1)));
		cnt -= cnt1;
		for (int j = 1; j <= cnt1; j++)
			printf("%d ",(1 << i));
	}
	putchar('\n');
	return 0;
}