#include <iostream>
#include <algorithm>

using namespace std;

struct goods{
	long long price;
	long long dis;
}N[200050];

bool cmp(goods a,goods b){
	if(a.price-a.dis < b.price-b.dis){
		return true;
	}else{
		return false;
	}
}

int main(int argc, char *argv[]) {
	long long all,now;
	long long spend = 0;
	cin >> all >> now;
	for(int i = 0;i < all;i++){
		cin >> N[i].price;
	}
	for(int i = 0;i < all;i++){
		cin >> N[i].dis;
	}
	sort(N,N+all,cmp);
	
	for(int i = 0;i < now;i++){
		spend += N[i].price;
		N[i].price = 0;
		N[i].dis = 0;
	}
	for(int i = now;i < all;i++){
		spend += min(N[i].dis,N[i].price);
	}
	cout << spend << endl;
	return 0;
}
