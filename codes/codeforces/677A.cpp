#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int width=0;
	while(n--)
	{
		int h;
		cin>>h;
		if(h>k)
		{
			width+=2;
		}
		else
		{
			width+=1;
		}
	}
	cout<<width;
return 0;
}