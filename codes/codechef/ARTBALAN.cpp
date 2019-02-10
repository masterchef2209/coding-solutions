#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int arr[26];
    for(int i=0;i<26;i++)
        arr[i]=0;
    for(int i=0;i<s.size();i++)
    {
      arr[s[i]-'A']++;
    }
    sort(arr,arr+26,greater<int>());
    int n=s.size();
    vector<int> factors;
    for(int i=1;i<=min(n,(int)26);i++)
    {
      if(n%i==0)
      {
        factors.emplace_back(i);
      }
    }
    int ans=LLONG_MAX;
    for(int o=0;o<factors.size();o++)
    {
      int u=factors[o];
      int d=n/u;
      int i=0;
      int sum=0;
      if(d>=arr[0])
      {
        while(i<u)
        {
            sum=sum+(d-arr[i]);
            i++;
        }
      }
      else
      {
          while(i<u && arr[i]>d)
          {
              sum=sum+(arr[i]-d);
              i++;
          }
          for(int kk=u;kk<26;kk++)
          {
              if(arr[kk]==0)
                break;
              else
                sum+=arr[kk];
          }
      }
      //cout<<u<<"-"<<d<<"-"<<sum<<" ";
      ans=min(ans,sum);
    }
    //cout<<endl;
    cout<<ans<<endl;
  } 
return 0;
}