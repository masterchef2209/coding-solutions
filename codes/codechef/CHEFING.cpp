#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[26]={0};
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			arr[s[i]-'a']=1;
		}
		for(int j=0;j<n-1;j++)
		{
			string s1;
			cin>>s1;
			set<int>bag;
			for(int i=0;i<s1.size();i++)
			{
				bag.insert(s1[i]-'a');
			}
			for(int i=0;i<26;i++)
			{
			    if(bag.find(i)!=bag.end())
			        arr[i]&=1;
			    else
			        arr[i]&=0;
			}
		}
		int cnt=0;
		for(int i=0;i<26;i++)
		{
		    //cout<<arr[i]<<" ";
			if(arr[i])
				cnt++;
		}
		//cout<<endl;
		cout<<cnt<<endl;
	}
return 0;
}