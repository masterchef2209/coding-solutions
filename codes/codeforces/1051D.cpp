#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353

ll dp[1007][2014][4]={0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    // state- index,number of components after selecting index,tile selected at index
    // types :- BB-0
    //          WW-1
    //          BW-2
    //          WB-3
    dp[1][1][0]=1;
    dp[1][1][1]=1;
    dp[1][2][2]=1;
    dp[1][2][3]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i][1][0]=1;
        dp[i][1][1]=1;
        dp[i][1][2]=0;
        dp[i][1][3]=0;
    }
    for(ll i=2;i<=n;i++)
    {
        for(ll j=2;j<=2*i;j++)
        {
            for(ll k=0;k<4;k++)
            {
                if(k==0)
                {
                    dp[i][j][k]=( (dp[i-1][j][0]+dp[i-1][j-1][1])%mod+(dp[i-1][j][2]+dp[i-1][j][3])%mod )%mod;
                }
                else if(k==1)
                {
                    dp[i][j][k]=( (dp[i-1][j-1][0]+dp[i-1][j][1])%mod+(dp[i-1][j][2]+dp[i-1][j][3])%mod )%mod;
                }
                else if(k==2)
                {
                    dp[i][j][k]=( (dp[i-1][j-1][0]+dp[i-1][j-1][1])%mod+(dp[i-1][j][2]+dp[i-1][j-2][3])%mod )%mod;
                }
                else if(k==3)
                {
                    dp[i][j][k]=( (dp[i-1][j-1][0]+dp[i-1][j-1][1])%mod+(dp[i-1][j-2][2]+dp[i-1][j][3])%mod )%mod;
                }
            }
        }
    }
    cout<< ( (dp[n][k][0]+dp[n][k][1])%mod+(dp[n][k][2]+dp[n][k][3])%mod )%mod;
return 0;
}