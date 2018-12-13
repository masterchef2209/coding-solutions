#include<bits/stdc++.h>
using namespace std;
//not accepted
long long q,k;
deque< pair<long long,long long > > Q;

inline bool bounded(long long color,long long C)
{
	if(color>=C-k && color<=C+k)
		return true;
	return false;
}

long long dp[200005];

long long func(long long i,long long j,long long C1,long long sum=0)
{
  //cout<<"+++++"<<sum<<endl;
  if(i>=Q.size())
    return 0;
  if(!bounded(Q[i].first,C1))
    dp[j]=func(i+1,j,C1,sum);
  else if(dp[j]!=-1)
    return dp[j];
  else if(Q[i].second>=0)
  {
    dp[j]=Q[i].second+func(i+1,j+1,C1,sum+Q[i].second);
  }
  else if(Q[i].second<0)
  {
    dp[j]=max({-sum+func(i+1,j+1,C1,0LL),Q[i].second+func(i+1,j+1,C1,sum+Q[i].second),0LL});
  }
  //cout<<dp[j]<<endl;
    return dp[j];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	cin>>q>>k;
	long long ans=0;
	while(q--)
	{
		long long b,C,d;
		cin>>b>>C;
		if(b==1)
		{
			cin>>d;
			Q.push_front(make_pair(C,d));
		}
		else if(b==2)
		{
			cin>>d;
			Q.push_back(make_pair(C,d));
		}
		else if(b==3)
		{
      memset(dp,-1,sizeof(dp));
			//long long sum=0;
			long long mm=0;
      long long C1=C^ans;
      //cout<<"----"<<C1<<endl;
      mm=max(mm,func(0,0,C1,0));
			// for(long long i=0;i<Q.size();i++)
			// {
			// 	if(bounded(Q[i].first,C1) && Q[i].second>0)
			// 	{
			// 		sum+=Q[i].second;
			// 		if(sum>mm)
			// 		{
			// 			mm=sum;
			// 		}
			// 	}
			// }
      cout<<mm<<endl;
			ans=mm;
		}
	}
  // for(long long i=0;i<Q.size();i++)
  // {
  //   cout<<Q[i].first<<" "<<Q[i].second<<endl;
  // }
return 0;
}