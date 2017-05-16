#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n,len;
string opps[55];
int cishu[55];

void rnr(int a){
	opps[a][len] = opps[a][0];
	for(int i = 0;i < len+1;i++){
		opps[a][i] = opps[a][i+1];
	}
}

int main(int argc, char *argv[]) {
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> opps[i];
	}
	len = opps[0].size();
	cishu[0] = 0;
	int cnt = 0;
	for(int i = 1;i < n;i++){
		for(int j = 0;j <= 2*len;j++){
			opps[i][len] = opps[i][0];
			for(int k = 0;k < len+1;k++){
				opps[i][k] = opps[i][k+1];
			}
			
			if(opps[0] != opps[i]){
				cnt++;
			}else{
				break;
			}
			if(j == 2*len){
				cout << "-1" << endl;
				return 0;
			}
		}
		cishu[i] = cnt;
		cnt = 0;
	}
	int sum = 0;
	//sort(cishu,cishu+n);
	for(int i = 0;i < n;i++){
		cout << cishu[i] << " ";
	}
}