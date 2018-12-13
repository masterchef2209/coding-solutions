#include<bits/stdc++.h>
using namespace std;

void primefact(long a,map<long,long>&ax,map<long,long>&ae)
{
  for(int i=2;i<=5;i++)
  {
    while(a%i==0)
    {
      ax[i]++;
      a/=i;
    }
  }
  for(int i=5;i<=sqrt(a);i++)
  {
    while(a%i==0)
    {
      ae[i]++;
      a/=i;
    }
  }
  if(a>1)
  {
    ae[a]++;
  }
}

int main()
{
  long x,y;
  cin>>x>>y;
  map<long,long> xx,xe,yx,ye;
  primefact(x,xx,xe);
  primefact(y,yx,ye);
  if(xe!=ye)
  {
    cout<<-1;
  }
  else
  {
    long ans=0;
    ans+=abs(xx[2]-yx[2]);
    ans+=abs(xx[3]-yx[3]);
    ans+=abs(xx[5]-yx[5]);
    cout<<ans;
  }
return 0;
}