#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll fib[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    fib[0]=1;
    fib[1]=1;
    for(ll i=2;i<100005;i++)
    {
        fib[i]=(fib[i-1]%mod + fib[i-2]%mod)%mod;
    }
    cout<<(2*( (fib[n]-1)%mod +fib[m]%mod))%mod;
return 0;
}