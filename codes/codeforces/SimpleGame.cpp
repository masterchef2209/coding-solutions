#include<bits/stdc++.h>
using namespace std;
int main()
{
	float n,m;
	cin>>n>>m;
	if(n==1 && m==1)
		cout<<(int)n;
	else if((n-m)>=n/2)
		cout<<(int)(m+1);
	else
		cout<<(int)(m-1);	
return 0;
}