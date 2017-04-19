#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int limak,bob,cnt = 0;
	cin >> limak >> bob;
	while(limak <= bob){
		limak *=3;
		bob *= 2;
		cnt++;
		//cout << limak << ' ' << bob << ' ' << cnt << endl;
	}
	cout << cnt;
}