#include<bits/stdc++.h>
using namespace std;
#define MAX 10000007
#define ll int
//not accepted(TLE)
ll v[MAX];
ll len, sp[MAX];

void Sieve(){
	for (ll i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (ll i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (long long j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  memset(v,0,sizeof(v));
	Sieve();
	ll n;
  while(cin>>n)
  {
    if(n==1)
    {
      cout<<1<<endl;
      continue;
    }
    cout<<1;
    while(n>1)
    {
		  cout<<" x "<<sp[n];
		  n/=sp[n];
	  }
    cout<<endl;
  }
	
    return 0;
}