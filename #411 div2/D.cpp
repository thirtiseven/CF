#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {  
	char sub[1000100];
	std::cin >> sub;
	int pos = 0;
	int sum = 0;
	int len = strlen(sub);
	while(1){
		if(sub[pos] == 'a') {			
			if(pos < len-2&&sub[pos+1] == 'a'&&sub[pos+2] == 'b'){
				if(pos < len - 3&&sub[pos+3] == 'a'){
					pos += 3;
					sum += 3;
				} else if(pos < len - 3&&sub[pos+3] == 'b'){
					sub[pos+3]='a';
					pos += 3;
					sum += 5;
				} else {
					sum += 3;
					break;
				}
			}else if(pos < len-1&&sub[pos+1]=='b') {
				if(pos < len-2&&sub[pos+2]=='a') {
					pos += 2;
					sum += 1;
				} else if(pos < len-2){
					sub[pos+2]='a';
					pos += 2;
					sum += 2;
				} else {
					sum++;
					break;
				}
			} else if(pos < len){
				pos++;
			} else {
				break;
			}
		} else {
			pos++;
		}
	}
	std::cout << sum << std::endl;
	return 0;
}