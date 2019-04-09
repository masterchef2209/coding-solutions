#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
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

ll dp[1005][1005];
ll weight[1005];
ll cost[1005];

int ind=1;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,m,c0,d0;
	cin>>n>>m>>c0>>d0;
	for(int i=0;i<m;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int x=a/b;
		while(x--)
		{
			weight[ind]=c;
			cost[ind]=d;
			ind++;
		}
	}
	for(int i=0;i<=n;i++)
	{
		dp[0][i]=d0*(i/c0);
	}
	for(int i=1;i<ind;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j<weight[i])
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],cost[i]+dp[i-1][j-weight[i]]);
			}
		}
	}
	cout<<dp[ind-1][n]<<endl;
    return 0;
}