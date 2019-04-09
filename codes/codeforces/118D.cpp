#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 100000000
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

ll dp[101][101][11][11];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	for(int f=0;f<=n1;f++)
	{
		for(int h=0;h<=n2;h++)
		{
			for(int kf=0;kf<=k1;kf++)
			{
				for(int kh=0;kh<=k2;kh++)
				{
					if(f+h==0)
						dp[f][h][kf][kh]=1;
					else
					{
						ll ans=0;
						if(f>0 && kf>0)
						{
							ans=(ans+dp[f-1][h][kf-1][k2])%mod;
						}
						if(h>0 && kh>0)
						{
							ans=(ans+dp[f][h-1][k1][kh-1])%mod;
						}
						dp[f][h][kf][kh]=ans%mod;
					}
				}
			}
		}
	}
	cout<<dp[n1][n2][k1][k2]<<endl;
    return 0;
}