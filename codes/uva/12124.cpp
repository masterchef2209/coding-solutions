#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define f first
#define s second


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,b;
		cin>>n>>b;
		map<string,vector< pair<ll,ll> > >mm;
		for(ll i=0;i<n;i++)
		{
			string a,b;
			cin>>a>>b;
			ll p,q;
			cin>>p>>q;
			mm[a].eb(mp(p,q));
		}
		ll low=0,high=1000000000;
		ll ans=-1;
		while(low<high)
		{
			ll mid=low+(high-low+1)/2;
			//if budget lower_bounded by mid quality is overshooting the given budget than move the quality down
			ll cost=0;
			for(auto &item:mm)
			{
				ll temp=1000000000;
				for(auto &obj:item.second)
				{
					if(obj.second>=mid)
					{
						temp=min(temp,obj.first);
					}
				}
				cost+=temp;
			}
			if(cost>b)
				high=mid-1;
			else
			{
				ans=max(ans,mid);
				low=mid;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}