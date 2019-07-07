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
 
#define int long long
 
const int MAX = 1e6 + 5;
long long size[MAX];
int arr[MAX];
pair< long long, pair<int,int> > p[MAX];
int n,m;
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
  }
  else
  {
    arr[rootB]=arr[rootA];
    size[rootA]+=size[rootB];
  }
}
 
ll ans=LLONG_MIN;
ll a0,b0;

void kruskal()
{
  for(int i=0;i<m;i++)
  {
    int a=p[i].second.first;
    int b=p[i].second.second;
    long long cost=p[i].first;
    if(root(a)!=root(b))
    {
      dsu(a,b);
    }
    if(root(a0)==root(b0))
    {
      ans=max(ans,cost);
      break;
    }
  }
}
 
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  initialize();
  cin>>n>>m;
  long long weight;
    ll a,b;
    cin>>a0>>b0>>weight;
    p[0]=make_pair(LLONG_MAX,make_pair(a0,b0));
    for(int i=1;i<m;i++)
    {
      int a,b;
      cin>>a>>b>>weight;
      p[i]=make_pair(weight,make_pair(a,b));
    }
    sort(p,p+m);
    kruskal();
    if(ans==LLONG_MAX)
    {
        cout<<"1000000000";
    }
    else
        cout<<ans;
    return 0;
}