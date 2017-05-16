#include <iostream>
#include <cstring>

using namespace std;


int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int snack[100100];
	int num[100100];
	memset(num,0,sizeof(num)); 
	int label = n;
	for(int i = 0;i < n;i++){
		cin >> snack[i];
		num[snack[i]]++;
		for(;num[label]==1;label--){
		  cout << label << " ";
		} 
		cout << "\n";
	}
	return 0;
}
