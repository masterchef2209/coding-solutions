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

#define INF (1<<29)

int d1[410][410];
int d2[410][420];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				d1[i][j]=0;
				d2[i][j]=0;
			}
			else
			{
				d1[i][j]=INF;
				d2[i][j]=1;
			}
		}
	}

	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		d1[a][b]=d1[b][a]=1;
		d2[a][b]=d2[b][a]=INF;
	}

	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d1[i][j]=min(d1[i][j],d1[i][k]+d1[k][j]);
				d2[i][j]=min(d2[i][j],d2[i][k]+d2[k][j]);
			}
		}
	}

	int ans=max(d1[1][n],d2[1][n]);
	if(ans==INF)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;

	return 0;
}