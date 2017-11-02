#include <iostream>

int main(int argc, char *argv[]) {  
	int n, a[1000];
	std::cin >> n;
	if(n%2){
		int i;
		for(i=0;i<n;++i)
			std::cin>>a[i];
		if(a[0]%2&&a[n-1]%2)
			std::cout<<"Yes"<<std::endl;
		else
			std::cout<<"No"<<std::endl;
	}
	else
		std::cout<<"No"<<std::endl;
	return 0;
}