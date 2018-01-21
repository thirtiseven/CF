#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main() {
		string a,b;
		cin>>a>>b;
		int len =a.length() - b.length();
		len = len>=0? len:0;
		for(int i=0;i<len;i++)
		{
				char temp = a[a.length()-i-1];
				a[a.length()-i-1] = a[i];
				a[i] = temp;
		}
		std::sort(a.begin(), a.end());
		std::reverse(a.begin(), a.end());
		if(a.length()<b.length())
		{
				cout<<a;
				return 0;
		}
		else
		{

				for(int i=len,k =0;i<a.length();i++,k++)
			 {
				 if(a[i] > b[k]) {
						if(i!=a.length()-1)
						{
								for(int j=i+1;a[i]>b[k];j++)
							 {
									char temp = a[i];
									a[i] = a[j];
									a[j] = temp;
							 }
						}
						else{
								 char temp = a[i];
									a[i] = a[i-1];
									a[i-1] = temp;
						}

				}
				 if(a[i]<b[k]) break;
			}
		}
		cout<<a;
		return 0;
}