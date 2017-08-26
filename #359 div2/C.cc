#include <iostream>
//#include <bits/stdc++.h>

int num[10], ans = 0;

void check(int x, int y, int n, int m) {
	for(int i = 0; i < 10; i++)num[i]=0;
	if(!n)num[0]++;
	if(!m)num[0]++;
	while(n){
		num[x % 7]++;
		x /= 7;
		n /= 7;
	}
	while(m){
		num[y % 7]++;
		y /= 7;
		m /= 7;
	}
	for(int i = 0; i < 10; i++)
		if(num[i]>1) {
			return;
		}
	ans++;
} 

int main(int argc, char *argv[]) {
	int n,m; 
	std::cin >> n >> m; 
	if(1ll*n*m>1e7){
		std::cout << "0\n";
		return 0;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			check(i,j,n-1,m-1);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}