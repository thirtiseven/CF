#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	int tempa,tempb,n,f=0,s=0;
	cin >> n;
	int fir[8],sec[8];
	for(int i = 0;i < 8;i++){
		fir[i] = 0;
		sec[i] = 0;
	}
	for(int i = 0;i < n;i++){
		cin >> tempa;
		fir[tempa]++;
	}
	for(int i = 0;i < n;i++){
		cin >> tempb;
		sec[tempb]++;
	}
	for(int j = 1;j <= 5;j++){
		if((fir[j] + sec[j])%2 == 0){
			if(fir[j] > sec[j]){
				f += (fir[j]-sec[j])/2;
			}
		}else{
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << f << endl;
}