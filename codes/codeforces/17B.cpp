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

//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)

//struct custom_hash {
//    static uint64_t splitmix64(uint64_t x) {
//        // http://xorshift.di.unimi.it/splitmix64.c
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//    size_t operator()(uint64_t x) const {
//        static const uint64_t FIXED_RANDOM = 
//            chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};

#define fi first
#define se second

ll n,m;

#define int long long

ll bulb=0;

const int MAX = 1e5+5;
long long size[MAX];
ll q[MAX];
ll q1[MAX];
int arr[MAX];
pair< long long, pair<int,int> > p[MAX];
void initialize()
{
  for(int i=0;i<MAX;i++)
  {
    arr[i]=i;
    size[i]=1;
  }
}

int root(int i)
{
  while(i!=arr[i])
  {
    arr[i]=arr[arr[i]];
    i=arr[i];
  }
return i;
}

void dsu(int a,int b)
{
  int rootA=root(a);
  int rootB=root(b);
  if(size[rootA]<size[rootB])
  {
    arr[rootA]=arr[rootB];
    size[rootB]+=size[rootA];
    q1[rootA]=max(q1[rootA],q1[rootB]);
    q1[rootB]=max(q1[rootA],q1[rootB]);
  }
  else
  {
    arr[rootB]=arr[rootA];
    size[rootA]+=size[rootB];
    q1[rootA]=max(q1[rootA],q1[rootB]);
    q1[rootB]=max(q1[rootA],q1[rootB]);
  }
}

long long kruskal()
{
  long long minCost=0;
  for(int i=0;i<m;i++)
  {
    int a=p[i].second.first;
    int b=p[i].second.second;
    long long cost=p[i].first;
    if(root(a)!=root(b))
    {
      if(q[b]!=q1[root(b)])
      {
      	continue;
      }
      dsu(a,b);
      minCost+=cost;
    }
  }
return minCost;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>q[i];
		q1[i]=q[i];
	}
	initialize();
	cin>>m;
	for(ll i=0;i<m;i++)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		p[i]=mp(w,mp(a,b));
	}
	sort(p,p+m);
	ll ans=kruskal();
	for(ll i=1;i<=n;i++)
	{
		arr[i]=root(i);
	}
	for(ll i=1;i<n;i++)
	{
		if(arr[i]!=arr[i+1])
		{
			bulb=1;
			break;
		}
	}
	if(bulb)
		cout<<-1;
	else
		cout<<ans;
    return 0;
}


//252908XL