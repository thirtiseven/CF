#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	long long b , d , s , sum = 0 , maxd;
	cin >> b >> d >> s;
	maxd = max(b,max(d,s));
	if(b < maxd - 1){
		sum += maxd - b - 1;
	}
	if(d < maxd - 1){
		sum += maxd - d  -1;
	}
	if(s < maxd - 1){
		sum += maxd - s - 1;
	}
	cout << sum << endl;
	return 0;
}