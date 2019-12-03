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

ll t;
vector<char>chickens;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(char a='a';a<='z';a++)
		chickens.eb(a);
	for(char a='A';a<='Z';a++)
		chickens.eb(a);
	for(char a='0';a<='9';a++)
		chickens.eb(a);
	cin>>t;
	while(t--)
	{
		ll r,c,k;
		char grid[110][110];
		cin>>r>>c>>k;
		ll ccount=0;
		for(ll i=1;i<=r;i++)
		{
			for(ll j=1;j<=c;j++)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='R')
				{
					ccount++;
					grid[i][j]='#';
				}
			}
		}
		ll di=ccount/k;
		ll rem=ccount%k;
		ll rem1=k-(ccount%k);


		ll xx=1,yy=1;

		ll pos=0;
		ll fl=0;
		while(rem--)
		{
			ll hehe=di+1;
			while(hehe>0)
			{
				if(grid[xx][yy]=='#')
					hehe--;
				grid[xx][yy]=chickens[pos];
				if(fl==0)
					yy++;
				else
					yy--;
				if(yy==(c+1))
				{
					yy=c;
					xx++;
					fl^=1;
				}
				if(yy==(0))
				{
					yy=1;
					xx++;
					fl^=1;
				}
			}
			if(xx==(r+1))
			    break;
			pos++;
		}

		while(rem1--)
		{
			ll hehe=di;
			while(hehe>0)
			{
				if(grid[xx][yy]=='#')
					hehe--;
				grid[xx][yy]=chickens[pos];
				if(fl==0)
					yy++;
				else
					yy--;
				if(yy==(c+1))
				{
					yy=c;
					xx++;
					fl^=1;
				}
				if(yy==(0))
				{
					yy=1;
					xx++;
					fl^=1;
				}
			}
			if(xx==(r+1))
			    break;
			pos++;
		}
		pos--;
        while(xx!=(r+1))
        {
            grid[xx][yy]=chickens[pos];
            	if(fl==0)
					yy++;
				else
					yy--;
				if(yy==(c+1))
				{
					yy=c;
					xx++;
					fl^=1;
				}
				if(yy==(0))
				{
					yy=1;
					xx++;
					fl^=1;
				}
        }
		for(ll i=1;i<=r;i++)
		{
			for(ll j=1;j<=c;j++)
			{
				cout<<grid[i][j];
			}
			cout<<"\n";
		}
	}
    return 0;
}


//252908XL