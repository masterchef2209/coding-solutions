#include<bits/stdc++.h>
using namespace std;
//not accepted
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,a,x,r;
	cin>>n>>m>>a>>x>>r;
	string s;
	cin>>s;
	set<string>pretty;
	vector< pair<string,int> >good;
	for(int i=0;i<m;i++)
	{
		string t;
		int c;
		cin>>t>>c;
		pretty.insert(t);
	}
	int flag=0;
	int yo;
	string xx;
	for(int i=0;i<a;i++)
	{
		string p;
		int q;
		cin>>p>>q;
		if(pretty.find(p)!=pretty.end())
		{
			xx=p;
			yo=q;
			flag=1;
		}
		good.emplace_back(make_pair(p,q));
	}
	if(flag==0)
		cout<<0;
	else
	{
		if(s.find(xx)!=string::npos)
		{
			int pp=s.find(xx);
			int count=0;
			vector<string>result;
			while(n<=1000000 && (x-count*yo)>yo)
			{
				string haha("");
				haha+="3 ";
				haha+=(to_string(pp+1)+" ");
				haha+=(pp+xx.size());
				n+=(xx.size());
				count++;
			}
			cout<<result.size()<<endl;
			for(int i=0;i<result.size();i++)
			{
				cout<<result[i]<<endl;
			}
		}
		else
			cout<<0;
	}
	return 0;
}