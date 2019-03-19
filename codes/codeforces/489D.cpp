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

vector< vi >succ(3005);
int arr[3005][3005];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			arr[i][j]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		succ[a].eb(b);
		arr[a][b]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				int count=0;
				for(auto &x:succ[i])
				{
					if(x!=i && x!=j && arr[x][j]==1)
						count++;
				}
				ans+=( ((count)*(count-1))/2 );
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}