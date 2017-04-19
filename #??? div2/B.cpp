#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n , l;
	cin >> n >> l;
	int kefa[110];
	int sasha[110];
	int flag;
	for(int i = 0;i < n;i++){
		cin >> kefa[i];
	}
	for(int i = 0;i < n;i++){
		cin >> sasha[i];
	}
	int disk[110];
	int diss[110];
	disk[0] = l-kefa[n-1]+kefa[0];
	diss[0] = l-sasha[n-1]+sasha[0];
	for(int i = 1;i < n;i++){
		disk[i] = kefa[i] - kefa[i-1];
		diss[i] = sasha[i] - sasha[i-1];
	}
	for(int i = 0;i !=n;i++){
		for(int j = 0;j != n;j++){
			if(disk[(j+i)%n] == diss[j]){
				flag++;
				if(flag == n-1){
					cout << "YES" << endl;
					return 0;
				}
			}else{
				flag = 0;
				break;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}