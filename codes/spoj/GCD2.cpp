#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		string b;
		cin>>a>>b;
    if(a==0)
    {
      cout<<b<<endl;
      continue;
    }
		string x="0";
		int b1=0;
		int n=b.size();
		for(unsigned int i=0;i<n;i++)
		{
			x+=b[i];	
			int digit=stoi(x);
			int rem=digit%a;
			if(i==n-1)
			{
				b1=rem;
			}
			x=to_string(rem);
		}
		cout<<gcd(a,b1)<<endl;
  }
return 0;
}
