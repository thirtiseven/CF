#include <iostream>
#include <string>

using namespace std;

//string input[2000200];
string temp;
long long faces = 0;


int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> temp;
		if(temp == "Tetrahedron"){
			faces += 4;
		}else if(temp == "Cube"){
			faces += 6;
		}else if(temp == "Octahedron"){
			faces += 8;
		}else if(temp == "Dodecahedron"){
			faces += 12;
		}else if(temp == "Icosahedron"){
			faces += 20;
		}
	}
	cout << faces;
	return 0;
}