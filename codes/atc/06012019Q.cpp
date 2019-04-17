#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

vector<ll>dp(2*500005,0);
ll n;


ll query(ll pos)
{
  ll ans=0;
  while(pos>=1)
  {
    ans=max(ans,dp[pos]);
    pos-=(pos&-pos);
  }
  return ans;
}

void update(ll pos,ll val)
{
  while(pos<=n)
  {
    dp[pos]=max(dp[pos],val);
    pos+=(pos&-pos);
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
  cin>>n;
  ll h[n];
  ll a[n];
  for(ll i=1;i<=n;i++)
  {
    cin>>h[i];
  }
  for(ll j=1;j<=n;j++)
  {
    cin>>a[j];
  }
  //base case
  update(h[1],a[1]);



  for(ll flower=2;flower<=n;flower++)
  {
      ll temp=query(h[flower])+a[flower];
      update(h[flower],temp);
  }
  cout<<query(n)<<endl;
    return 0;
}