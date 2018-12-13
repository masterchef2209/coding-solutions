#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
  int i;
	for(i=0;i<n-1;i++)
	{
		if(s[i]>s[i+1])
			break;
	}
	string x=s.substr(0,i)+s.substr(i+1,n-i-1);
	cout<<x;
return 0;
}