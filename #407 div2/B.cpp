#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int b1,q,l,m;
	cin >> b1 >> q >> l >> m;
	int temp;
	int badcount = 0;
	int oooooo = 0;
	for(int i = 0;i < m;i++){
		cin >> temp;
		while(1){
			if(temp>l){
				break;
			}
			if(q == 0){
				
			}
			if(temp%b1==0){
				if(temp == b1){
					badcount++;
					oooooo = 1;
				}
				temp /= b1;
				while(temp % q == 0&&q!=1){
					temp /= q;
					if(temp == 1){
						badcount++;
						break;
					}
				}
			}
			break;
		}	
	}
	if(q == 1){
		if(oooooo){
			cout << 0;
		}else{
			cout << "inf";
		}
		return 0;
	}
	int that = b1;
	int count = 0;
	while(that <= l){
		count++;
		that*=q;
	}
//	cout << badcount << ' ' << count << endl;
	cout << count - badcount;
	return 0;
}