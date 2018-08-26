#include<bits/stdc++.h>
using namespace std;

int main()
{
	string n;
	cin>>n;
	int ans=0;
	for(unsigned int i=0;i<n.size();i++)
	{
		if(n[i]=='4' || n[i]=='7')
			ans++;
	}
	if(ans==4 || ans==7)
    cout<<"YES";
  else
    cout<<"NO";
return 0;
}