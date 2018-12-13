#include<bits/stdc++.h>
using namespace std;

vector< pair<long,long> >vv;
int sieve[20000007];
void precompute()
{
	sieve[0]=1;
	sieve[1]=1;
	for(long i=2;i*i<=20000007;i++)
	{
		if(sieve[i]==0)
		{
			for(long j=2*i;j<=20000007;j+=i)
			{
				sieve[j]=1;
			}
		}
	}
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(sieve,0,sizeof(sieve));
	precompute();
	vv.push_back(make_pair(3,5));
	for(long i=6;i<=20000007;i+=6)
	{
		if(sieve[i-1]==0 && sieve[i+1]==0)
		{
			vv.push_back(make_pair(i-1,i+1));
		}
	}
  // for(long i=0;i<=100;i++)
  // {
  //   cout<<"("<<vv[i].first<<", "<<vv[i].second<<")\n";
  // }
	long num;
	while(cin>>num)
	{
		cout<<"("<<vv[num-1].first<<", "<<vv[num-1].second<<")\n";
	}
return 0;
}