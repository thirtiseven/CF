#include <iostream>  
#include <algorithm> 
#include <cstring> 
 
char s[105]; 
int sort[4],order[4],cnt[4];  

int main(int argc, char *argv[]) {   
	std::cin >> s;  
	int len = strlen(s); 
	for(int i=0;i<len;i++) {  
		order[i%4]++;
		if(s[i]=='R') {
			sort[0]=i%4;
			cnt[0]++; 
		}else if(s[i]=='B') {		
			sort[1]=i%4;
			cnt[1]++;  
		}else if(s[i]=='Y') {
			sort[2]=i%4;
			cnt[2]++; 
		}else if(s[i]=='G') {
			sort[3]=i%4;
			cnt[3]++; 
		}
	}  
	for(int i=0;i<4;i++) { 
		std::cout << order[sort[i]]-cnt[i] << " ";  
	}
	return 0;  
}  