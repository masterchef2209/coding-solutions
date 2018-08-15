#include<bits/stdc++.h>
using namespace std;

int main()
{
  int f;
  cin>>f;
  set<int> fr;
  set<int> fof;
  for(int i=0;i<f;i++)
  {
    int t1;
    cin>>t1;
    fr.insert(t1);
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
      int temp;
      cin>>temp;
      fof.insert(temp);
    }
  }
  int ans=0;
  set<int>::iterator it;
  for(it=fof.begin();it!=fof.end();it++)
  {
    set<int>::iterator found;
    found=fr.find(*it);
    if(found==fr.end())
      ans++;
  }
  cout<<ans;
return 0;
}
