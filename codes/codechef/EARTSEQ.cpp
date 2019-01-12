#include<bits/stdc++.h>
using namespace std;
//not accepted

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    long long n1=n-3;
		cout<<6<<" "<<15<<" ";
		long long a=5;
		int kko=1;
		while(1)
		{
			if(n1<=0)
				break;
			if(a>=3333)
			{
				cout<<3333*pow(5,++kko)<<" ";
				a=5;
				n1--;
				continue;
			}
			if((a+2)%3==0)
			{
				cout<<a*(a+4)<<" ";
				a+=2;
				n1--;
			}
			else
			{
				cout<<a*(a+2)<<" ";
				n1--;
			}
			a+=2;
		}
		cout<<a*2;
	cout<<endl;	
	}
return 0;
}