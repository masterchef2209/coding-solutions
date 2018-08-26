#include<bits/stdc++.h>
using namespace std;
//not accepted
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    stack<long> no;
    stack<char>op;
    long a;
    cin>>a;
    n=n-1;
    while(n--)
    {
      char g;
      cin>>g;
      long h;
      cin>>h;
      op.push(g);
      no.push(h);
    }
    long long ans=0;
    while(!no.empty())
    {
      if(op.top()=='+')
      {
        ans+=no.top();
        no.pop();
      }
      else
      {
        ans+=no.top();
        no.pop();
        ans*=-1;
      }
      op.pop();
    }
    cout<<ans+a<<endl;
  }
return 0;
}