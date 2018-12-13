#include<bits/stdc++.h>
using namespace std;

long long lcm(long long a,long long b)
{
  return a/__gcd(a,b)*b;
}

int main()
{
	long long n;
	int m;
	while(cin>>n>>m)
	{
		set<long long>ss;
		long long result=n;
		for(int u=0;u<m;u++)
		{
			long long x;
			cin>>x;
			ss.insert(x);
		}
		vector<long long>vv(ss.begin(),ss.end());
		for(int j=0;j<(1<<vv.size());j++)
		{
			vector<long long>temp;
      //cout<<"{";
			for(int i=0;i<vv.size();i++)
			{
				if(j&(1<<i))
				{
					temp.push_back(vv[i]);
          //cout<<vv[i]<<" ";
				}
			}
      //cout<<"}"<<endl;
			long long lm=1;
			for(int k=0;k<temp.size();k++)
			{
				lm=lcm(lm,temp[k]);
			}
      //cout<<lm<<endl;
      if(temp.size()!=0)
      {
        if(temp.size()&1)
			  {
				  result-=(n/lm);
			  }
			  else
			  {
				  result+=(n/lm);
			  }
      }
		}
		cout<<result<<endl;
	}
return 0;
}