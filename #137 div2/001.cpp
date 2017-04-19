#include <iostream>
#define MAX 10000

using namespace std;

int main(int argc, char *argv[]) {
	int k , r , number ;
	cin >> k >> r;
	for(number = 1;number < MAX;number++){
		if(((k*number-r)%10==0)||k*number%10==0){
			cout << number;
			break;
		}
	}
	return 0;
}