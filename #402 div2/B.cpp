#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>

#define INF 2147483600

using namespace std;
int main(int argc, char *argv[]) {
	char num[15];
	for(int i = 0;i < 15;i++){
		num[i] = '0';
	}
	int k;
	cin >> num >> k;
	int tozero,normal = 0;
	int zeronum = 0;
	int len = strlen(num);
	tozero = len - 1;
	for(int i = len-1;zeronum < k;i--){
		if(i == 0){
			normal = INF;
			break;
		}else{
			if(num[i] != '0'){
				normal++;
			}else{
				zeronum++;
			}
		}
//		cout << zeronum << ' ' << normal << ' ' << i<<endl;
	}
	cout << min(tozero,normal);
	return 0;
}