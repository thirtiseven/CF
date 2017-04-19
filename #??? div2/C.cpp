#include <iostream>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

char password[70][70];
int status[70][70];
int onex = -1,oney = -1,twox = -1,twoy = -1,thrx = -1,thry = -1;
pair<int,int> one(-1,-1);
pair<int,int> two(-1,-1);
pair<int,int> thr(-1,-1);
set<int> how;

int what(char a){
	if(a == '#' || a == '*' || a == '&'){
		return 3;
	}else if((a <= 90 && a >= 65) || (a <= 122 && a>=97)){
		return 2;
	}else if(a <= 57 && a >= 48){
		return 1;
	}else{
		return 0;
	}
}


int main(int argc, char *argv[]) {
	int m,n;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> password[i][j];
			status[i][j] = what(password[i][j]);
			if(status[i][j] == 1&&one.first == -1 && i != two.first && i != thr.first){
				one.first = i;
				one.second = j;
			}else if(status[i][j] == 2&&two.first == -1 && i != one.first && i != thr.first){
				two.first = i;
				two.second = j;
			}else if(status[i][j] == 3&&thr.first == -1 && i != two.first && i != one.first){
				thr.first = i;
				thr.second = j;
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = m-1;j >= 0;j--){
			if(status[i][j] == 1&&(m-j-1)<one.second&& i != two.first && i != thr.first){
				one.first = i;
				one.second = n-j+1;
			}else if(status[i][j] == 2&&(m-j-1)<two.second&& i != one.first && i != thr.first){
				two.first = i;
				two.second = n-j+1;
			}else if(status[i][j] == 3&&(m-j-1)<thr.second && i != two.first && i != one.first){
				thr.first = i;
				thr.second = n-j+1;
			}
		}
	}
	cout << one.first << two.first << thr.first << endl;
	cout << one.second << two.second << thr.second << endl;
	int maxmove = one.second + two.second + thr.second;
	cout << maxmove << endl;
	return 0;
}