#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll x,y;
	cin>>x>>y;
	ll count=0;
	ll sides[3];
	sides[0]=y;
	sides[1]=y;
	sides[2]=y;
	for(ll i=0;i<=1000000;i++)
	{
	        //cout<<sides[0]<<" "<<sides[1]<<" "<<sides[2]<<endl;
		if(sides[0]>=x && sides[1]>=x && sides[2]>=x)
			break;
	    sides[i%3]=sides[(i+1)%3]+sides[(i+2)%3]-1;
	    count++;
	}
    cout<<count<<endl;
	return 0;
}