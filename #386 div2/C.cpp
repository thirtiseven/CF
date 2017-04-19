#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int s,x1,x2;
	int t1,t2;
	int p,d;
	cin >> s >> x1 >> x2;
	cin >> t1 >> t2;
	cin >> p >> d;
	int times = 0;
	int dt = d;
	int di = (x2-x1>0?1:-1);
	if(dt==1)  
	{  
		if(p<=x1 && x1<x2){  
			times = (x2-p)*t1;  
		}else if(x1 < x2){  
			times = (2*s-p+x2)*t1;  
		}else if(x2<x1){ 
			times=(2*s-p-x2)*t1; 
		}
	}  
	else if(dt==-1)  
	{  
		if(p>=x1 && x2<x1){  
			times=(p-x2)*t1;  
		}else if(x2<x1){  
			times=(p+2*s-x2)*t1;  
		}else if(x1<x2){  
			times=(p+x2)*t1;
		}
	}  
	if(times>di*(x2-x1)*t2)  
		cout << di*(x2-x1)*t2;  
	else  
		cout << times; 
	return 0;
}