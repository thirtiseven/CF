#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int main(int argc, char *argv[]) {
	char wow[20];
	cin >> wow;
	int len = strlen(wow);
	int cnt = 0;
	for(int i = 0; i < len/2; i++){
		if(wow[i] != wow[len-1-i]){
			cnt++;
		}
	}
	if(cnt == 1||len == 1||(cnt==0&&len%2==1)){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}