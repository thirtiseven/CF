#include <iostream>
int n,L,a,t,l,s=0,q=0;
int main(){
	std::cin>>n>>L>>a;
	for(int i=0;i<n;i++){
		std::cin>>t>>l;
		q+=(t-s)/a;
		s=t+l;
	}
	std::cout<<q+(L-s)/a<<'\n';
}