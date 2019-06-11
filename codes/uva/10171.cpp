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

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

#define INF (1<<29)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	while(cin>>n)
	{
		if(n==0)
			break;
		ll young[1001][1001];
		ll old[1001][1001];
		for(ll i=1;i<=1000;i++)
		{
		    for(ll j=1;j<=1000;j++)
		    {
		        young[i][j]=INF;
		        old[i][j]=INF;
		    }
		}
		ll mm=-1;
		for(ll u=0;u<n;u++)
		{
			char a,b,c,d;
			ll weight;
			cin>>a>>b>>c>>d>>weight;
			mm=max(mm,(ll)(c-'A')+1);
			mm=max(mm,(ll)(d-'A')+1);
			if(c!=d)
			{
			if(a=='Y')
			{
				young[(c-'A')+1][(d-'A')+1]=weight;
				if(b=='B')
					young[(d-'A')+1][(c-'A')+1]=weight;
			}
			else
			{
				old[(c-'A')+1][(d-'A')+1]=weight;
				if(b=='B')
					old[(d-'A')+1][(c-'A')+1]=weight;
			}
			}
		}
		for(ll i=1;i<=mm;i++)
		{
			young[i][i]=0;
			old[i][i]=0;
		}
		for(ll k=1;k<=mm;k++)
		{
			for(ll i=1;i<=mm;i++)
			{
				for(ll j=1;j<=mm;j++)
				{
					young[i][j]=min(young[i][j],young[i][k]+young[k][j]);
					old[i][j]=min(old[i][j],old[i][k]+old[k][j]);
				}
			}
		}
		
// 		for(ll i=1;i<=mm;i++)
// 		{
// 		    for(ll j=1;j<=mm;j++)
// 		    {
// 		        cout<<young[i][j]<<" ";
// 		    }
// 		    cout<<endl;
// 		}
		
		char yo,ol;
		cin>>yo>>ol;
		ll yo1,ol1;
		yo1=(yo-'A')+1;
		ol1=(ol-'A')+1;
		ll crycry=INF;
		for(ll i=1;i<=mm;i++)
		{
			if((young[yo1][i]+old[ol1][i])<crycry)
			{
				crycry=(young[yo1][i]+old[ol1][i]);
			}
		}
		vector<char>ans;
		for(ll i=1;i<=mm;i++)
		{
			if((young[yo1][i]+old[ol1][i])==crycry)
			{
				ans.eb((i-1+'A'));
			}
		}
		
		if(crycry==INF)
		{
			cout<<"You will never meet.\n";
		}
		else
		{
			cout<<crycry<<" ";
			for(ll ch=0;ch<ans.size();ch++)
			{
				cout<<ans[ch];
				if(ch<ans.size()-1)
				    cout<<" ";
			}
			cout<<"\n";
		}
	}
    return 0;
}