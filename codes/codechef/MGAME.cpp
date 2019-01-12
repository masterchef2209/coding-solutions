#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,p;
    	cin>>n>>p;
    	if(n==1 || n==2)
    	{
    		cout<<p*p*p<<endl;
    		continue;
    	}
    	cout<<(p-n%(n/2+1))*(p-n%(n/2+1))+(p-n)*(p-n)+(p-n)*(p-n%(n/2+1))<<endl;
	}
return 0;
}