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
	int a,b;
	int testcase=1;
	while(1)
	{
		int dist[110][110];
		for(int i=1;i<=100;i++)
		{
			for(int j=1;j<=100;j++)
			{
				if(i==j)
					dist[i][j]=0;
				else dist[i][j]=INF;
			}
		}
		
		string s;
		getline(cin,s);
		istringstream is(s);
		int noo=0;
		int mm=-1;
		while(is>>a)
		{
			is>>b;
			if(a==0 && b==0)
			{
				if(noo==0)
					return 0;
				break;	
			}
			else
			{
				dist[a][b]=1;
				mm=max(mm,a);
				mm=max(mm,b);
			}
			noo++;
		}
		for(int k=1;k<=mm;k++)
		{
			for(int i=1;i<=mm;i++)
			{
				for(int j=1;j<=mm;j++)
				{
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		double temp=0;
		double cc=0;
		for(int i=1;i<=mm;i++)
		{
			for(int j=1;j<=mm;j++)
			{
				if(i!=j && dist[i][j]!=INF)
				{
					temp+=dist[i][j];
					cc+=1;
				}
			}
		}
		cout<<"Case "<<testcase++<<": average length between pages = ";
		cout<<fixed<<setprecision(3)<<temp/cc<<" clicks\n";
	}
    return 0;
}