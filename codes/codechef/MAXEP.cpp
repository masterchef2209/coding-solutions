#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long N,c;
  cin>>N>>c;
  //if(N>1000)
  {
    long long z=ceil(sqrt((N)));
    long long i=0;
    for(;i<=N;i++)
    {
      if(i*z+1>N)
      {
        i-=1;
        break;
      }
      cout<<1<<" "<<i*z+1<<endl;
      long long res;
      cin>>res;
      if(res==1)
      {
        cout<<2<<endl;
        i-=1;
        break;
      }
    }
    long long stas=i*z+1;
    long long enn=(i+1)*z+1;
    if(stas<1)
    {
      stas=1;
    }
    if(enn>N)
    {
      enn=N;
    }
    long long z1=ceil(sqrt((enn-stas+1)));
    long long i1=0;
    for(;i1<=N;i1++)
    {
      if(stas+i1*z1>enn)
      {
        i1-=1;
        break;
      }
      cout<<1<<" "<<stas+i1*z1<<endl;
      long long res;
      cin>>res;
      if(res==1)
      {
        cout<<2<<endl;
        i1-=1;
        break;
      }
    }
    long long j=stas+i1*z1;
    if(j<stas)
    {
      j=stas;
    }
    for(;j<=N;j++)
    {
      cout<<1<<" "<<j<<endl;
      long long res;
      cin>>res;
      if(res==1)
      {
        cout<<2<<endl;
        cout<<3<<" "<<j<<endl;
        break;
      }
    }
  }
  // else
  // {
  //   int i;
  //   for(i=1;i<=N;i++)
  //   {
  //     cout<<1<<" "<<i<<ennl;
  //     int res;
  //     cin>>res;
  //     if(res==1)
  //       break;
  //   }
  //   cout<<3<<" "<<i<<ennl;
  // }
  return 0;
}