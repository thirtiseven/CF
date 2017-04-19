#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	long long even,odd;
	cin >> even >> odd;
	if((abs(odd - even) == 1 || odd == even) && odd >= 0 && even >= 0 && odd <= 100 && even <= 100 && !(odd == even && odd == 0 && even == 0)){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}