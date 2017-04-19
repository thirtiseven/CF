#include <iostream>

using namespace std;
int exam[100100] , prepare[100100];

int main(int argc, char *argv[]){
	int n , m , j , predays = 0 , sum[100100] = {0} , days = -1;
	cin >> n >> m;
	int total = m*(m+1)/2;
	for (int i = 1 ; i <= n; i++){
		cin >> exam[i];
	}
	for (int i = 1 ; i <= m; i++){
		cin >> prepare[i];
	}
	for (int i = 1 ; i <= n; i++){
		if(exam[i] == 0){
			predays++;
		}else{
			j = exam[i];
			if(predays >= prepare[j]){
				predays -= prepare[j];
				sum[i] = sum[i-1] + j;
				if(sum[i] == total){
					days = i;
				}
			}else if(i >= prepare[j]){
				predays -= prepare[j];
				sum[i] = sum[i-prepare[j]] + j;
				if(sum[i] == total&&i<days){
					days = i;
				}
			}else{
				predays++;
			}
		}
	}
	cout << days << endl;
	return 0;
}