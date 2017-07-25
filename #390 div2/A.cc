#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
  
int main(){  
	int k, m = 0, n;  
	int cnt = 0; 
	int a[110],b[110],c[110];  
	std::cin >> n; 
	for(int i = 1; i <= n; i++) {  
		scanf("%d",&a[i]);  
		if(a[i] != 0)  
		  m++;  
	}  
	if(m == 0) {  
		std::cout << "NO\n";  
	}     
	for(int i = 1; i <= n; i++) {  
		cnt++;
		b[cnt] = i; 
		while(a[i] == 0) {  
			i++;
		}
		m--;
		if(m == 0) {  
			break; 
		}
		c[cnt] = i; 
	} 
	c[cnt] = n;  
	std::cout << "YES\n" << cnt << std::endl;  
	for(int i = 1; i <= cnt; i++){  
		std::cout << b[i]  << " " << c[i] << std::endl;  
	}  
	return 0;  
}  
