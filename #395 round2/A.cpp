#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;
int main(int argc, char *argv[]) {
	int n , m,z;
	cin >> n >> m >> z;
	int cnt = 0;
	for(int i = 1;i <= z;i++){
		if(i%n==0&&i%m==0){
			cnt++;
		}
	}
	cout << cnt << endl;
}