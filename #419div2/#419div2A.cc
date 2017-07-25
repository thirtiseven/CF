#include <iostream>

int main(int argc, char *argv[]) {  
	int a, b;
	scanf("%d:%d", &a, &b);
	int cnt = 0;
	while(1) {
		if(a/10 == b%10 && b/10 == a%10) {
			break;
		} else {
			cnt++;
			if(b == 59) {
				if(a==23) {
					a=0;
				} else {
					a++;
				}
				b = 0;
			} else {
				b++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}