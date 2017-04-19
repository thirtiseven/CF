#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n , k;
	cin >> n >> k;
	int amount[100020];
	int days = 0;
	for(int i = 0;i < n;i++){
		cin >> amount[i];
		while(amount[i]>k){
			days++;
			amount[i] -= k;
		}
		days++;
	}
	cout << (days+1)/2;
	return 0;
}