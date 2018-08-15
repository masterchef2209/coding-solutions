#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    map<string,int> m;
    cin>>n;
    while(n--)
    {
      string s;
      int loop=6;
      while(loop--)
      {
        string temp;
        cin>>temp;
        s+=temp;
        s+=" ";
      }
      m[s]++;
    }
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
      cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
  }
return 0;
}
