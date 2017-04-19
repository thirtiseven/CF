#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	int n , q;
	cin >> n >> q;
	int swap1,swap2;
	int times = 0;
	int arr[200000];
	for(int i = 1;i <= n;i++){
		arr[i] = i;
	}
	int count;	
	for(int i = 1;i <= q;i++){
		cin >> swap1 >> swap2;
		if(swap1 > swap2){
			swap(swap1,swap2);
		}
		swap(arr[swap1],arr[swap2]);
		if(arr[swap1] >= arr[swap2]){
			for(int i = swap1;i < swap2;i++){
				if(arr[swap1] >= arr[i]){
					count++;
				}	
			}
			times += count;
			count = 0;
		}else{
			for(int i = swap1;i < swap2;i++){
				if(arr[swap2] >= arr[i]){
					count++;
				}	
			}
			times -= count;
			count = 0;
		}
		cout << times << endl;
	}
	return 0;
}