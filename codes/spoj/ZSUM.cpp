#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 10000007

ll bpow(ll a,ll b)
{
	ll res=1;
  while(b>0)
  {
    if(b&1)
	  {
		  res=(res*a)%MOD;
	  }
	  a=(a*a)%MOD;
	  b>>=1;
  }
return res;
}

int main()
{
	ll n,k;
	cin>>n>>k;
	while(n!=0 || k!=0)
	{
		cout<< (bpow(n,k)+bpow(n,n)+bpow(n-1,k)+bpow(n-1,k)+bpow(n-1,n-1)+bpow(n-1,n-1))%MOD <<endl;
	cin>>n>>k;
	}
return 0;
}