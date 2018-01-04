#include <iostream>
using namespace std;
int a[7]={0};
int f(int n)
{ if((n%400==0)||((n%100!=0)&&(n%4==0)))
		return 1;
	return 0;}
void m(int c)
{ switch(c){
	case 6: a[0]++;break;
	case 0: a[1]++;break;
	case 1: a[2]++;break;
	case 2: a[3]++;break;
	case 3: a[4]++;break;
	case 4: a[5]++;break;
	case 5: a[6]++;break;
	 default: break;}}
int main()
{
	int n;cin>>n;
	int c,sum=0;
	for(int i=1900;i<1900+n;i++)
	{ if(f(i)==1) sum+=366;
		else sum+=365;}
  for(int i=1900+n-1;i>=1900;i--)
	{for(int j=12;j>=1;j--;){
			if(j==12&&i==1900+n-1)
			{ sum-=18;c=sum%7;m(c);}
			else if(j==2&&f(i)==1){sum-=29;c=sum%7;m(c);}
			else   if(j==2&&f(i)==0){sum-=28;c=sum%7;m(c);}
			else   if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)
		{sum-=31;c=sum%7;m(c);}
	 else{sum-=30;c=sum%7;m(c);}}}
	for(int i=0;i<7;i++)cout<<a[i]<<" ";
	cout<<endl;
	return 0;}