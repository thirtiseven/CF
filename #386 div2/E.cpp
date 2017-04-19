#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	int n,m;
	cin >> n >> m;
	int alice[200100];
	int num[200100] = {0};
	for(int i = 0;i < 200100;i++){
		num[i] = 0;
	}
	int odd = 0 , even = 0 , maxm = 0 , mtoe = 0 , mtoo = 0;
	for(int i = 0;i < n;i++){
		cin >> alice[i];
		num[alice[i]]++;
		if((alice[i]%2)==0){
			even++;
		}else{
			odd++;
		}
		if(alice[i] > maxm){
			maxm = alice[i];
		}
	}
	int ome = (even - odd)/2;
	for(int i = 0;i <= maxm;i+=2){
		if(num[i] > 0){
			mtoo += (num[i]-1);
		}
	}
	for(int i = 1;i <= maxm;i+=2){
		if(num[i] > 0){
			mtoe += (num[i]-1);
		}
	}
	int cnt;
	if(ome >= 0){
		cnt = max(ome,mtoo) + mtoe;
	}else{
		cnt = max(-ome,mtoe) + mtoo;
	}
	cout << cnt << ' ' << mtoo << ' ' << mtoe << ' ' << ome << ' ' << even << ' ' << odd << endl;
	for(int i = n-1;i >= 0;i--){
		if(num[alice[i]]>1){
			if(ome > 0){
				for(int j = 1;j <= m;j+=2){
					if(j==m){
						cnt = -1;
						break;
					}
					if(num[j] == 0){
						alice[i] = j;
						num[alice[i]]--;
						num[j]++;
						break;
					}
				}
				ome--;
			}else if(ome < 0){
				for(int j = 2;j <= m;j+=2){
					if(j==m){
						cnt = -1;
						break;
					}
					if(num[j] == 0){
						alice[i] = j;
						num[alice[i]]--;
						num[j]++;
						break;
					}
				}
				ome++;
			}
		}
	}
	
	cout << endl;
	for(int i = 0;i < n;i++){
		cout << alice[i] << ' ';
	}
	cout << endl;
	
	int j;
	int flago = 0, flage = 0;
	for(int i = 0;i < n;i++){
		if(alice[i]%2==0){
			if(flage == 0){
				flage = 1;
				continue;
			}
			for(j = 1;j <= m;j+=2){
				if(j==m){
					cnt = -1;
					break;
				}
				if(num[j] != 0){
					continue;
				}else{
					alice[i] = j;
					num[alice[i]]--;
					num[j] = 1;
					break;
				}
			}
			j = 1;
		}else if(alice[i]%2==1){
			if(flago == 0){
				flago = 1;
				continue;
			}
			for(j = 2;j <= m;j+=2){
				if(j==m){
					cnt = -1;
					break;
				}
				if(num[j] != 0){
					continue;
				}else{
					alice[i] = j;
					num[alice[i]]--;
					num[j] = 1;
					break;
				}
			}
			j = 2;
		}
	}
	cout << cnt << endl;
	if(cnt == -1){
//		return 0;
	}
	for(int i = 0;i < n;i++){
		cout << alice[i] << ' ';
	}
	cout << endl;
	return 0;
}