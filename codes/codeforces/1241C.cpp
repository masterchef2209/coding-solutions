		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll q;
	cin>>q;
	while(q--)
	{
		ll n;
		cin>>n;
		vector<ll>p(n),p1(n+1,0);
		for(ll i=0;i<n;i++)
		{
			ll tmp;
			cin>>tmp;
			tmp/=100;
			p[i]=tmp;
		}
		sort(p.rbegin(),p.rend());
		p1[0]=0;
		p1[1]=p[0];
		for(ll i=1;i<n;i++)
		{
			p[i]+=p[i-1];
			p1[i+1]=p[i];
		}
		ll x,a;
		cin>>x>>a;
		ll y,b;
		cin>>y>>b;
		ll k;
		cin>>k;
		vector< pair<ll,ll> >data;
		for(ll i=1;i<=n;i++)
		{
			if(i%a==0 && i%b==0)
			{
				data.eb(i,x+y);
			}
			else
			{
				if(i%a==0)
				{
					data.eb(i,x);
				}
				if(i%b==0)
				{
					data.eb(i,y);
				}
			}
		}
		ll ans=-1;
		ll cx=0,cy=0,cxy=0;
		for(ll lol=0;lol<data.size();lol++)
		{
			pair<ll,ll>pp=data[lol];
			if(pp.se==x)
			{
				cx++;
			}
			else if(pp.se==y)
			{
				cy++;
			}
			else
			{
				cxy++;
			}
			ll sum=0;
			if(x>y)
			{
				sum+=((x+y)*(p1[cxy]-p1[0]));
				sum+=(x*(p1[cxy+cx]-p1[cxy]));
				sum+=(y*(p1[cxy+cx+cy]-p1[cxy+cx]));
			}
			else
			{
				sum+=((x+y)*(p1[cxy]-p1[0]));
				sum+=(y*(p1[cxy+cy]-p1[cxy]));
				sum+=(x*(p1[cxy+cx+cy]-p1[cxy+cy]));
			}
			if(sum>=k)
			{
				ans=max(ans,(pp.fi));
				break;
			}
		}
		cout<<ans<<"\n";
	}
    return 0;
}


//252908XL