#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	int n,m,k,a[110];
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++){
		cin >> a[i] ;
	}
	int j,h,min1 = 100000,min2 = 100000;
	for(j = m-1;j<n;j++){
		if(a[j]!=0&&a[j]<=k){
			//cout << "biu" << endl;
			min1 = (j-m+1)*10;
			break;
		}
	}
	for(j = m-1;j>=0;j--){
		if(a[j]!=0&&a[j]<=k){
			//cout << "mua" << endl;
			min2 = (m-1-j)*10;
			break;
		}
	}
	//cout << min1 << ' ' << min2 << endl;
	cout << min(min1,min2);
}