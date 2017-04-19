#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>


using namespace std;
int bad[100100]; 
int main(int argc, char *argv[]){
	long long b1,q,l,m;
	cin >> b1 >> q >> l >> m;
	bad[m] = 10000000;
	for(long long i = 0;i < m;i++){
		cin >> bad[i];
	}
	sort(bad,bad+m);
	if(abs(b1)>l){ 
		cout << "0"; 
		return 0;
	}
	long long statusb1 = bad[lower_bound(bad,bad+m,b1)-bad];
	long long statusm = bad[lower_bound(bad,bad+m,-b1)-bad];
	long long statusze = bad[lower_bound(bad,bad+m,0)-bad];
	//cout << statusb1 << ' ' << statusm << ' ' << statusze << endl;
	if(b1 == 0 || q == 1){
		if(statusb1 == b1){
			cout << "0";
		}else{
			cout << "inf";
		}
		return 0;
	}
	if(q == 0){
		if(statusze!=0){
			cout << "inf";
		}else if(statusb1==b1)  {
			cout << "0";
		}else{
			cout << "1";
		}
		return 0;
	}
	if(q == -1){
		if(statusb1 == b1 && statusm==-b1){
			cout << 0;
		}else{
			cout << "inf";
		}
		return 0;
	}
	long long that = b1;
	long long count = 0;
	while(abs(that) <= l){  
		long long status=bad[lower_bound(bad,bad+m,that)-bad];  
		if(status!=that){ 
			count++;  
		}
		that *= q;
	} 
	cout << count;
	return 0;
}
