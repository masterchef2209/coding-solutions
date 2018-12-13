#include<bits/stdc++.h>
using namespace std;

long long lcm(long long a,long long b)
{
	return (a*b)/__gcd(a,b);
}

int main()
{
	int n,t;
	cin>>n>>t;
	while(n!=0 && t!=0)
	{
		vector<long long>vv;
	  for(int u=0;u<n;u++)
	  {
		  long long x;
		  cin>>x;
		  vv.push_back(x);
	  }
	  for(int v=0;v<t;v++)
	  {
	  	long long mn=LLONG_MAX;
	  	long long mx=LLONG_MIN;
		  long long h;
		  cin>>h;
		  for(int a=0;a<n;a++)
	 	  {
	  		for(int b=a+1;b<n;b++)
	  		{
	  			for(int c=b+1;c<n;c++)
	  			{
	  				for(int d=c+1;d<n;d++)
	  				{
	  					long long y=lcm(vv[a],lcm(vv[b],lcm(vv[c],vv[d])));
	  					if(h%y==0)
	  					{
	  						cout<<h<<" "<<h<<endl;
	  						goto label;
	  					}
	  					else
	  					{
	  						long long p=(h/y)*y;
	  						long long q=(h/y+1)*y;
	  						if(p>mx)
	  						{
	  							mx=p;
	  						}
	  						if(q<mn)
	  						{
	  							mn=q;
	  						}
	  					}
	  				}
	  			}
	  		}
	  	}
      cout<<mx<<" "<<mn<<endl;
	    label:;
	  }
  cin>>n>>t;
	}
return 0;
}