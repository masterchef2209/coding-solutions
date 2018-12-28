#include<bits/stdc++.h>
using namespace std;

long long triangle[100][100];

void precompute()
{
  long long y=64,x=64;
  memset(triangle,0,sizeof(triangle));
  triangle[0][0]=1;
  for(long long i=1;i<=64;i++)
  {
    triangle[i][0]=1;
    for(long long j=1;j<=i;j++)
    {
      triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
    }
  }
}

int main()
{
  precompute();
  // for(int i=0;i<=10;i++)
  // {
  //   for(int j=0;j<=10;j++)
  //   {
  //     cout<<triangle[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  long long n,m,t;
  cin>>n>>m>>t;
  long long ans=0;
  for(long long i=4,j=t-4;(i<=t-1)&&(j>=1);i++,j--)
  {
    // cout<<n<<"C"<<i<<endl;
    // cout<<m<<"C"<<j<<endl;
    ans+=(triangle[n][i]*triangle[m][j]);
  }
  cout<<ans;
return 0;
}