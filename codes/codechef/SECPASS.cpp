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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		vector<int>pos;
		for(int i=0;i<n;i++)
		{
			if(s[i]==s[0])
				pos.eb(i);
		}
		int x=0;
		int flag=0;
		while(1)
		{
			x++;
			for(int i=0;i<pos.size();i++)
			{
				if(pos[i]+x>=n || s[x]!=s[pos[i]+x])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		cout<<s.substr(0,x)<<endl;
	}
    return 0;
}