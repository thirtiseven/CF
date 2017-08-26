#include <iostream>
#include <cstdio>
#define maxn 1005

int main(int argc, char *argv[]) { 
	int a[maxn];
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	if(a[n]==0)return puts("UP");
	if(a[n]==15)return puts("DOWN");
	if(n==1)return puts("-1");
	if(a[n-1]<a[n])return puts("UP");
	if(a[n-1]>a[n])return puts("DOWN");
}