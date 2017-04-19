#include <iostream>

using namespace std;
int a[550] , b[550];
int main(int argc, char *argv[]) {
	int n , k , addition = 0, i = 1;
	cin >> n >> k;
	for(int i=1;i <= n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	for(int i = 1;i <= n;i++){
		if(b[i] + b[i+1] < k){
			b[i+1] += k - b[i] - b[i + 1];
		}
	}
//	if(b[n-1] + b[n] < k){
//		b[n] += k - b[n - 1] - b[n];
//	}
	
	for(i=1;i <= n;i++){
		addition += b[i]-a[i];
	}
	cout << addition << endl;
	cout << b[1];
	for(i=2;i <= n;i++){
		cout << ' ' << b[i];
	}
	cout << endl;
	return 0;
}