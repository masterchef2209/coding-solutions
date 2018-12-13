#include<bits/stdc++.h>
using namespace std;

int ti;
int k;
void func(int h,int a)
{
	k++;
  //cout<<h<<" "<<a<<endl;
	if(h<=0 || a<=0)
	{
		return;
	}
	if(k%2==0)
	{
		func(h+3,a+2);
		ti++;
	}
	else
	{
    double H,A;
	  H=(double)h/20;
	  A=(double)a/10;
    //cout<<"("<<H<<" "<<A<<")"<<endl;
		if(H<A)
		{
			func(h-5,a-10);
		}
		else
		{
			func(h-20,a+5);
		}
		ti++;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		k=-1;
		ti=0;
		int h,a;
		cin>>h>>a;
		func(h,a);
		cout<<ti-1<<endl;
	}
return 0;
}