#include<bits/stdc++.h>
using namespace std;
#define MM 2000000011

long long bpow(long long x,long long y)
{
  long long res=1;
  while(y)
  {
    if(y&1)
      res=(res*x)%MM;
    x=(x*x)%MM;
    y>>=1;
  }
  return res;
}

int main()
{
	int n;
	cin>>n;
	for(int u=1;u<=n;u++)
	{
		int x;
		cin>>x;
    if(x==1 || x==2)
      cout<<"Case #"<<u<<": "<<1<<endl;
    else
    {
      long long ans=(bpow(x,x-2))%MM;
		  cout<<"Case #"<<u<<": "<<ans<<endl;
    }
	}
return 0;
}