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
	string s;
	cin>>s;
	int n=s.size();
	if(n&1)
	{
		cout<<-1<<endl;
		return 0;
	}
	int l=0,r=0,u=0,d=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L')
		{
			l++;
		}
		else if(s[i]=='R')
		{
			r++;
		}
		else if(s[i]=='U')
		{
			u++;
		}
		else if(s[i]=='D')
		{
			d++;
		}
	}
	int diff1=abs(l-r);
	int diff2=abs(u-d);
	int smaller=min(diff1,diff2);
	int greater=max(diff1,diff2);
	cout<< ( smaller + (greater-smaller)/2 ) <<endl;
    return 0;
}