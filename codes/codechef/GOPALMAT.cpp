#include <bits/stdc++.h>
#define ll long long int
using namespace std;
//not accepted
int main(){
  ll n,q;
  cin>>n>>q;
  ll h[n];
  for(ll i=0;i<n;i++){
    cin>>h[i];
  }
  ll a,b,ans=0,l,r;
  for(int i=0;i<q;i++){
    cin>>a>>b;
    l=(a+ans)%n;
    r=(b+ans)%n;
    ll temp;
    if(l>r){
      temp=l;
      l=r;
      r=temp;
    }
    ll count=1,max=h[l];
    for(ll j=l;j<=r;j++){
      if(max<h[j]){
        count++;
        max=h[j];
      }
    }
    ans = count;
    cout<<count<<endl;
  }
  return 0;
}
