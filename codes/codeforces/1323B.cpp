		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

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
	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll>row(n),col(m);
	for(ll i=0;i<n;i++)
	{
		cin>>row[i];
	}
	for(ll i=0;i<m;i++)
	{
		cin>>col[i];
	}
	vector<ll>rowb,colb;
	ll ccount=0;
	for(ll i=0;i<n;i++)
	{
		if(row[i]==1)
		{
			ccount++;
		}
		else
		{
			rowb.eb(ccount);
			ccount=0;
		}
	}
	if(ccount!=0)
	{
		rowb.eb(ccount);
	}
	ccount=0;
	for(ll i=0;i<m;i++)
	{
		if(col[i]==1)
		{
			ccount++;
		}
		else
		{
			colb.eb(ccount);
			ccount=0;
		}
	}
	if(ccount!=0)
	{
		colb.eb(ccount);
	}
	ccount=0;
	sort(rowb.begin(),rowb.end());
	sort(colb.begin(),colb.end());
    ll rowbsize=rowb.size();
    ll colbsize=colb.size();
    vector<ll>prerow(rowbsize,0);
    vector<ll>precol(colbsize,0);
    prerow[rowbsize-1]=rowb[rowbsize-1];
    for(ll i=rowbsize-2;i>=0;i--)
    {
        prerow[i]=prerow[i+1]+rowb[i];
    }
    precol[colbsize-1]=colb[colbsize-1];
    for(ll i=colbsize-2;i>=0;i--)
    {
        precol[i]=precol[i+1]+colb[i];
    }
    ll ans=0;
    vector<ll>divi;
    for(ll i=1;i*i<=k;i++)
    {
        if(k%i==0)
        {
            divi.eb(i);
            ll j=k/i;
            if(j!=i)
            {
                divi.eb(j);
            }
        }
    }
    for(auto &fa:divi)
    {
        if(k%fa==0)
        {
            auto it=lower_bound(rowb.begin(),rowb.end(),fa);
            if(it==rowb.end())
                continue;
            ll pos=it-rowb.begin();
            ll why=rowbsize-pos;
            ll val1=prerow[pos]-(why*fa)+why;
            ll fa1=k/fa;
            auto it1=lower_bound(colb.begin(),colb.end(),fa1);
            if(it1==colb.end())
                continue;
            ll pos1=it1-colb.begin();
            ll why1=colbsize-pos1;
            ll val2=precol[pos1]-(why1*fa1)+why1;
            ans+=(val1*val2);
        }
    }
    cout<<ans;
    return 0;
}


//252908XL