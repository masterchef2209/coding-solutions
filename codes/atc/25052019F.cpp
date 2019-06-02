    /*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

//not accepted

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
//typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;
#define int long long
#define fi first
#define se second

ll ss=0;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  priority_queue<ll,vector<ll>,greater<ll> > upper;
    priority_queue<ll> lower;
  ll q;
  cin>>q;
  ll sum=0;
  ll tot=0;
  ll count=0;
  while(q--)
  {
    ll st;
    cin>>st;
    if(st==1)
    {
      ll a,b;
      cin>>a>>b;
      sum+=b;
      tot+=a;
      count++;
      if(lower.empty())
      {
        lower.push(a);
        ss+=a;
      }
      else
      {
        if(a<=lower.top())
        {
          lower.push(a);
          ss+=a;
        }
        else
        {
          upper.push(a);
        }
        if(lower.size()-upper.size()==2)
        { 
          upper.push(lower.top());               
          ss-=(lower.top());
          lower.pop();                     
        }
        if(upper.size()-lower.size()==1)
        {
          lower.push(upper.top());  
          ss+=(upper.top());
          upper.pop(); 
        }
      }
    }
    else
    {
      ll val=lower.top();
      ll pp=tot+sum+val-2*ss;
      if(!(count&1))
          pp=pp-val;
      cout<<val<<" "<<pp<<"\n";
    }
  }
    return 0;
}