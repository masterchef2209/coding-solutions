#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	char s[n+1];
	cin>>s;
	int ans=0;
	for(int i=1;i<n;i++)
	{
		set<char>temp;
		temp.insert('R');
		temp.insert('B');
		temp.insert('G');
		if(s[i]==s[i-1])
		{
			ans++;
			temp.erase(s[i]);
			if(i+1<n)
				temp.erase(s[i+1]);
			auto val= *temp.begin();
			s[i]=val;
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<s[i];
	}
return 0;
}