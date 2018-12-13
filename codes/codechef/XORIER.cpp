#include<bits/stdc++.h>
using namespace std;
//partially accepted

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    long arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        long yy=arr[i]^arr[j];
        if(yy>=4 && yy%2==0)
        {
          ans++;
        }
      }
    }
    cout<<ans<<endl;
  }
return 0;
}