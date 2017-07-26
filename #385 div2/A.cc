#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream>  
#include <algorithm>    
  
int main(int argc, char *argv[]) {  
	char s[51][51];  
	std::cin >> s[0]; 
	int i = 1, j, t, cnt = 1;  
	for(j = 0; j < strlen(s[0]); j++) {  
		s[i][0] = s[i - 1][strlen(s[0]) - 1];  
		strcpy(&s[i][1], s[i - 1]);  
		s[i][strlen(s[0])] = '\0';  
		i++;  
		for(t=0;t<i-1;t++) {  
			if(strcmp(s[i-1],s[t])==0) {  
				break;  
			}  
		}  
		if(t == i-1) {  
			cnt++;  
		}  
	}  
	std::cout << cnt << "\n";  
	return 0;  
}  