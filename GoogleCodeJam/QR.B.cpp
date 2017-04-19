#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	ofstream fout ("B-largeout.txt"); 
	ifstream fin ("B-large.in.txt");  
	
	int n;
	fin >> n;
	
	for(int time = 1;time <= n;time++){
		char number[20];
		fin >> number;
		int status = (int)(number[0]-'0');
		int label = -1;
		for(int i = 0;i < strlen(number)-1;i++){
			if((int)(number[i+1]-'0') < status){
				label = i;
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
		if(label >=0){
			number[label] -= 1;
			for(int j = label+1;j < strlen(number);j++){
				number[j] = '9';
			}
		}
		fout << "Case #" << time << ": "; 
		if(number[0]=='0'){
			for(int i = 1;i < strlen(number);i++){
				fout << number[i];
			}
		}else{
			fout << number;
		}
		fout << endl;
	}
	return 0;
}