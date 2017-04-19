#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	long long n , m;
	cin >> n >> m;
	long long c = 2 * n - 2 * m;
	long long ago;
	double delta = (sqrt(1+8*(double)(n-m))-1)/2.0;
	long long deltaint;
	if(delta != (long long)delta){
		deltaint = (long long)(delta+1);
	}else{
		deltaint = (long long)(delta);
	}
	
	ago = m + deltaint;
	if(n <= m){
		ago = n;
	}
	cout << ago;
	return 0;
}