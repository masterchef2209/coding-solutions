#include<bits/stdc++.h>
using namespace std;

long long getnine(long long a)
{
	long long count=0;
	string s=to_string(a);
	int i=s.size()-1;
	while(i>=0 && s[i]=='9')
	{
		count++;
		i--;
	}
return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long p,d;
	cin>>p>>d;
	long long llimit=p-d;
	long long nop=getnine(p);
	long long ans=p;
	for(int m=1;m<=20;m++)
	{
		long long temp=p-(p%(long long)pow(10,m))-1;
		if(temp<llimit)
			break;
		ans=temp;
	}
	long long noans=getnine(ans);
	if(nop>=noans)
	{
		cout<<p<<endl;
	}
	else
		cout<<ans<<endl;
	return 0;
}