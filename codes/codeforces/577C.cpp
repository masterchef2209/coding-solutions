#include<bits/stdc++.h>
using namespace std;

bool isPrime(int a)
{
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
			return false;
	}
return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int>ans;
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(isPrime(i))
		{
			int k=i;
			int pp=1;
			while(((int)pow(k,pp))<=n)
			{
				ans.emplace_back((int)pow(k,pp));
				pp++;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
return 0;
}