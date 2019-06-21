		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

#define bip(n) __builtin_popcount(n)//no of ones bit in binary!!
#define bictz(n) __builtin_ctz(n)//no of trailing zeroes in binary!!
#define biclz(n) __builtin_clz(n)//no of leading zeroes in binary!!
#define bffs(n) __builtin_ffs(n)//index of first one bit!!

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

//#define fi1 ifstream cin("input.txt")
//#define of1 ofstream cout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll need[513]={0};
	for(ll i=1;i<=n;i++)
	{
		ll tmp;
		cin>>tmp;
		ll mask=0;
		while(tmp--)
		{
			ll a;
			cin>>a;
			a-=1;
			mask|=(1ll<<a);
		}
		need[mask]++;
	}
	vector< pair<ll,ll> >bag[513];
	for(ll i=1;i<=m;i++)
	{
		ll c;
		cin>>c;
		ll mask=0;
		ll tmp;
		cin>>tmp;
		while(tmp--)
		{
			ll a;
			cin>>a;
			a-=1;
			mask|=(1ll<<a);
		}
		bag[mask].eb(mp(c,i));
	}
	for(ll i=0;i<513;i++)
	{
	    if(bag[i].empty())
	        continue;
	    sort(bag[i].begin(),bag[i].end());
	}
	ll pehla=1,dusra=2,climit=INT_MAX,nn=0;
	for(ll mmask=0;mmask<513;mmask++)
	{
		if(bag[mmask].empty())
			continue;
		for(ll mmask1=mmask;mmask1<513;mmask1++)
		{
			if(bag[mmask1].empty())
				continue;
			ll cost=0;
			ll a1=1,b1=2;
			if(mmask==mmask1)
			{
				if(bag[mmask].size()<2)
					continue;
				cost=bag[mmask][0].fi+bag[mmask][1].fi;
				a1=bag[mmask][0].se;
				b1=bag[mmask][1].se;
			}
			else
			{
				cost=bag[mmask][0].fi+bag[mmask1][0].fi;
				a1=bag[mmask][0].se;
				b1=bag[mmask1][0].se;
			}
			ll mmaskeq=mmask|mmask1;
			ll numsatisfied=0;
			for(ll mmask2=0;mmask2<513;mmask2++)
			{
				if((mmaskeq|mmask2)==mmaskeq)
				{
					numsatisfied+=need[mmask2];
				}
			}
			//cout<<a1<<" "<<b1<<" "<<cost<<" "<<numsatisfied<<" "<<endl;
			if(numsatisfied>nn)
			{
				nn=numsatisfied;
				climit=cost;
				pehla=a1;
				if(pehla!=b1)
					dusra=b1;
			}
			else if( (numsatisfied==nn) && (cost<climit) )
			{
				climit=cost;
				pehla=a1;
				if(pehla!=b1)
					dusra=b1;
			}
		}
	}
	if(pehla>dusra)swap(pehla,dusra);
	cout<<pehla<<" "<<dusra;
    return 0;
}