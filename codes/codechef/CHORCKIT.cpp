#include<bits/stdc++.h>
using namespace std;
//not accepted
#define int long long
string s;


bool cmp(pair<string,int>&a,pair<string,int>&b)
{
	int ff,ss;
	ff=s.find(a.first);
	ss=s.find(b.first);
	return ff>ss;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,a,x,r;
	cin>>n>>m>>a>>x>>r;
	cin>>s;
	vector< pair<string,int> >good,pretty,qq;
	string stl;
	int ssize=LLONG_MIN;
	for(int i=0;i<m;i++)
	{
		string t;
		int c;
		cin>>t>>c;
		pretty.emplace_back(t,c);
		if(c > ssize)
		{
			ssize=c;
			stl=t;
		}
	}
	for(int i=0;i<a;i++)
	{
		string p;
		int q;
		cin>>p>>q;
		good.emplace_back(p,q);
	}
	for(int i=0;i<good.size();i++)
	{
		for(int j=0;j<pretty.size();j++)
		{
			if(pretty[j].first==good[i].first && s.find(good[i].first)!=string::npos)
			{
				break;
			}
		}
		qq.emplace_back(good[i]);
	}
	vector<string>result;
	sort(qq.begin(),qq.end(),cmp);
	for(int i=0;i<qq.size();i++)
	{
		int l,r;
		l=s.find(qq[i].first)+1;
		if(l>0)
		{
		    r=s.find(qq[i].first)+(qq[i].first.size());
		if(n+(qq[i].first.size())>1000000 || x-qq[i].second<0)
			break;
		n+=(qq[i].first.size());
		x-=qq[i].second;
		int j;
		for(j=0;j<a;j++)
		{
			if(good[j].first==qq[i].first)
				break;
		}
		string haha("");
		haha+="2 ";
		haha+=(to_string(l)+" ");
		haha+=(to_string(r)+" ");
		haha+=(to_string(j+1)+" ");
		result.emplace_back(haha);
		}
	}
	if(s.find(stl)!=string::npos)
	{
		int pp=s.find(stl);
		//cout<<pp<<endl;
		if(n+(stl.size())<=1000000 && x-r>0)
		{
			string haha("");
			haha+="3 ";
			haha+=(to_string(pp+1)+" ");
			haha+=(to_string(pp+stl.size()));
			result.emplace_back(haha);
		}
	}
	cout<<result.size()<<endl;
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]<<endl;
	}
	return 0;
}