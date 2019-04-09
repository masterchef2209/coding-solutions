#include <bits/stdc++.h>
/*

//By Tushar Gautam
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e;++i)
#define forsn(i,s,e) for(int i = s; i < e;++i)
#define rforn(i,s) for(int i = s; i >= 0;--i)
#define rforsn(i,s,e) for(int i = s; i >= e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime ((double)clock()/CLOCKS_PER_SEC)
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=1e5+5,MOD=1e9+7;
int t,n,m,k,x,y,w;
vector<string> in;
vv32 d;
bool valid(int i,int j,int di){
	return i<n && i>=0 && j<m && j>=0 && d[i][j]>di;
}
bool P(int k){
	int sm=MOD,sM=-MOD,dm=MOD,dM=-MOD;
	forn(i,n){
		forn(j,m){
			if(d[i][j]>k){
				sm=min(sm,i+j);
				sM=max(sM,i+j);
				dm=min(dm,i-j);
				dM=max(dM,i-j);
			}
		}
	}
	forn(i,n){
		forn(j,m){
			bool y=1;
			if(i+j+k<sM) y=0;
			if(i+j-k>sm) y=0;
			if(i-j+k<dM) y=0;
			if(i-j-k>dm) y=0;
			if(y) return 1;
		}
	}
	return 0;
}
void solve(int c){
	cin>>n>>m;
	in.resize(n);
	d.assign(n,v32(m,MOD));
	queue<p32> q;
	forn(i,n){
		cin>>in[i];
		forn(j,m){
			if(in[i][j]=='1') d[i][j]=0,q.push(mp(i,j));
		}
	}
	while(!q.empty()){
		auto tp=q.front(); q.pop();
		tie(x,y)=tp;
		int dd=d[tp.fi][tp.se];
		if(valid(x-1,y,1+dd)) d[x-1][y]=1+dd,q.push(mp(x-1,y));
		if(valid(x+1,y,1+dd)) d[x+1][y]=1+dd,q.push(mp(x+1,y));
		if(valid(x,y-1,1+dd)) d[x][y-1]=1+dd,q.push(mp(x,y-1));
		if(valid(x,y+1,1+dd)) d[x][y+1]=1+dd,q.push(mp(x,y+1));
	}
	int l=0,r=500;
	while(l<r){
		int mid=(l+r)/2;
		if(P(mid)) r=mid;
		else l=mid+1;
	}
	cout<<"Case #"<<c<<": "<<l<<ln;
}
signed main(){
	fastio;
	int c=0;
	testcase(tt) solve(++c);
	return 0;
}

*/

//this solution is for only small test case. gives tle for large test case

//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
using namespace std;

//using namespace __gnu_pbds;
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
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

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

char arr[300][300];

ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};

#define INF LLONG_MAX;
ll r,c;

inline bool ingrid(ll x,ll y)
{
    return (x>=0 && y>=0 && x<r && y<c);
}

// ll calculate(ll x,ll y)
// {
// 	if(arr[x][y]=='1')
// 		return 0;
// 	ll visited[r+1][c+1]={0};
// 	queue< pair<ll,pair<ll,ll> > >Q;
// 	pair<ll,ll>source=mp(x,y);
// 	Q.push(mp(0,source));
// 	visited[x][y]=1;
// 	while(!Q.empty())
// 	{
// 		pair<ll,pair<ll,ll> >temp=Q.front();
// 		Q.pop();
// 		if(!ingrid(temp.second.first,temp.second.second))
// 			continue;
// 		visited[temp.second.first][temp.second.second]=1;
// 		if(arr[temp.second.first][temp.second.second]=='1')
// 			return temp.first;
// 		for(ll i=0;i<4;i++)
// 		{
// 			pair<ll,ll>nei=mp(temp.second.first+dx[i],temp.second.second+dy[i]);
// 			if(ingrid[nei.first][nei.second] && !visited[nei.first][nei.second])
// 			{
// 				Q.push(mp(temp.first+1,mp(nei.first,nei.second)));
// 			}
// 		}
// 	}
// 	return INF;
// }

vector< pair<ll,ll> >points;

ll calculate1(ll x,ll y)
{
    	if(arr[x][y]=='1')
     		return 0;
    ll mm=LLONG_MAX;
    for(auto &o:points)
    {
        mm=min(mm,abs(x-o.first)+abs(y-o.second));
    }
    return mm;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin>>t;
	for(ll u=1;u<=t;u++)
	{
	    points.clear();
		cin>>r>>c;
		ll count=0;
		for(ll i=0;i<r;i++)
		{
			for(ll j=0;j<c;j++)
			{
				cin>>arr[i][j];
				if(arr[i][j]=='0')
				{
				    count++;
				}
				else
				{
				    points.eb(mp(i,j));
				}
			}
		}
		if(count==0)
		{
		    cout<<"Case #"<<u<<": "<<0<<endl;
		    continue;
		}
// 		ll mm=LLONG_MIN;
// 		ll xx,yy;
// 		for(ll i=0;i<r;i++)
// 		{
// 			for(ll j=0;j<c;j++)
// 			{
// 				ll temp=calculate(i,j);
// 				if(temp>mm)
// 				{
// 					mm=temp;
// 					xx=i;
// 					yy=j;
// 				}
// 			}
// 		}
        ll ans=LLONG_MAX;
		for(ll i=0;i<r;i++)
		{
		    for(ll j=0;j<c;j++)
		    {
		        if(arr[i][j]=='0')
		        {
		            arr[i][j]='1';
		            points.eb(mp(i,j));
		            ll haha=0;
		            for(ll x1=0;x1<r;x1++)
		            {
		              for(ll y1=0;y1<c;y1++)
		              {
		                  ll temp=calculate1(x1,y1);
 				            if(temp>haha)
				            {
					            haha=temp;
			        	    }
		              }
		            }
		            ans=min(ans,haha);
		            points.pop_back();
		            arr[i][j]='0';
		        }
		    }
		}
// 		arr[xx][yy]='1';
// 		ll mm1=LLONG_MIN;
// 		for(ll i=0;i<r;i++)
// 		{
// 			for(ll j=0;j<c;j++)
// 			{
// 				ll temp=calculate(i,j);
// 				if(temp>mm1)
// 				{
// 					mm1=temp;
// 				}
// 			}
// 		}
		cout<<"Case #"<<u<<": "<<ans<<endl;
	}
    return 0;
}