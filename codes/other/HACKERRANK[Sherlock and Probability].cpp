#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll prefixsum[100005];
ll n,k;
string s;
void initi()
{
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
			prefixsum[i]=1;
        else
            prefixsum[i]=0;
		if(i>0)
		{
			prefixsum[i]+=prefixsum[i-1];
		}
	}
}

ll sumsum(int i)
{
	ll a=max((ll)0,i-k);
	ll b=min((ll)n-1,i+k);
	if(a==0)
		return prefixsum[b];
	else
		return (prefixsum[b]-prefixsum[a-1]);
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cin>>s;
        initi();
		ll den=n*n;
		ll num=0;
		for(ll i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				num+=(sumsum(i));
			}
			
		}
		if(num==0)
			cout<<"0/1"<<endl;
		else
			cout<<num/__gcd(num,den)<<"/"<<den/__gcd(num,den)<<endl;
	}
return 0;
}

