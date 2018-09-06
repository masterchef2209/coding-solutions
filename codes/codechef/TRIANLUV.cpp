#include<bits/stdc++.h>
#define ll long long int
#define MM 1000000007
using namespace std;
//not accepted
ll gcd(ll a, ll b)
{
    if (b == 0)
       return a;
    return gcd(b, a%b);
}

ll getCount(ll x1,ll y1,ll x2,ll y2)
{
    if (x1==x2)
        return abs(y1 - y2) - 1;
    if (y1 == y2)
        return abs(x1-x2) - 1;
 
    return gcd(abs(x1-x2), abs(y1-y2))-1;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		ll n1=getCount(x1,y1,x2,y2);
		ll n2=getCount(x2,y2,x3,y3);
		ll n3=getCount(x3,y3,x1,y1);
    //cout<<n1<<" "<<n2<<" "<<n3<<endl;
		ll a1=((((n1%MM)*(n2%MM))%MM)*(n3%MM))%MM;
		ll a2=((1%MM)+((((2*n1%MM)+(2*n2%MM))%MM+(2*n3)%MM)%MM))%MM;
		ll ans=(a1+a2)%MM;
		cout<<ans<<endl;
	}
return 0;
}