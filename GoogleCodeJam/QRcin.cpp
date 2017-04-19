#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
//	ofstream fout ("A-out.txt"); 
//	ifstream fin ("A-large.in.txt"); 
	//ifstream fin ("NO.txt");   
	
	int n;
	cin >> n;
	
	for(int time = 1;time <= n;time++){
		char number[20];
		cin >> number;
		int status = (int)(number[0]-'0');
		//cout << status << endl;
		int label = -1;
		for(int i = 0;i < strlen(number)-1;i++){
			if((int)(number[i+1]-'0') < status){
				label = i;
				//cout << strlen(number) << endl;
				if(label == 0){
					label = 0;
				}else{
					while(label>=1&&number[label-1] == number[label]){
						label--;
					}
				}
				break;
			}
			status = (int)(number[i+1]-'0');
		}
		//	cout << label << endl;
				//cout << "TEST" << endl;
		if(label >=0){
			number[label] -= 1;
			//cout << number[label] << ' ' << strlen(number) << endl;
			for(int j = label+1;j < strlen(number);j++){
					//cout << "TEST " ;
				number[j] = '9';
			}
		}
			//cout << number[label+1] << endl;
				//cout << label << endl;
		//cout << "TEST" << endl;
		cout << "Case #" << time << ": "; 
		if(number[0]=='0'){
			for(int i = 1;i < strlen(number);i++){
				cout << number[i];
			}
		}else{
			cout << number;
		}
		cout << endl;
	}
	return 0;
}