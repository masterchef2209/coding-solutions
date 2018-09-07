#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  if(n==1 || n==2)
  {
    cout<<"No"<<endl;
  }
  else
  {
    cout<<"Yes"<<endl;
    if(n&1)
    {
      cout<<n/2+1<<" ";
      for(int i=1;i<=n;i+=2)
      {
        cout<<i<<" ";
      }
      cout<<endl;
      cout<<n/2<<" ";
      for(int i=2;i<=n;i+=2)
      {
        cout<<i<<" ";
      }
      cout<<endl;
    }
    else
    {
      cout<<n/2<<" ";
      for(int i=1;i<=n;i+=2)
      {
        cout<<i<<" ";
      }
      cout<<endl;
      cout<<n/2<<" ";
      for(int i=2;i<=n;i+=2)
      {
        cout<<i<<" ";
      }
      cout<<endl;
    }
  }
return 0;
}