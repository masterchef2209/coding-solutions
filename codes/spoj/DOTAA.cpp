#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,D,flag=0;
    cin>>n>>m>>D;
    multiset<int> heroes;
    for(int i=0;i<n;i++)
    {
      int temp;
      cin>>temp;
      heroes.insert(temp);
    }
    while(m--)
    {
      multiset<int>::iterator it=heroes.end();
      it--;
      int temp=*it-D;
      if(temp<=0)
      {
        flag=1;
        break;
      }
      else
      {
        heroes.erase(it);
        heroes.insert(temp);
      }
    }
    if(flag==1)
    {
      cout<<"NO\n";
    }
    else
    {
      cout<<"YES\n";
    }
  }
return 0;
}
