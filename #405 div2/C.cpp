#include <iostream>
#include <string>
#include <cstring>

using namespace std;


string difname[60] = {"Alice","Bob","Clare","Dave","Eve","Frank","Grant","Hook","Isella","Jack","Krus","Lily","Mark","Nueur","Okafor","Poor","Quant","Risk","Sara","Tidy","Ufo","Victor","Wow","Xrame","Ying","Zip","Zippo","Www","Vczh","Uno","Tick","Shadow","Rape","Qwqqqq","Pig","Oniang","New","Mike","Lee","Knock","Jake","Ill","Horrible","Grill","Fuck","Eye","Dick","Clear","Bruno","Alfred","Opps"};

int main(int argc, char *argv[]) {
	string status;
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n-k+1;i++){  
		cin >> status;  
		if(status[0]=='N'){  
			difname[i+k-1]=difname[i];  
		}  
	} 

	cout << difname[0];
	for(int i = 1;i < n;i++){
		cout << " " << difname[i];
	}
	cout << endl;
	return 0;
}