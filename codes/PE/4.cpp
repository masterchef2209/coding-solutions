#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long n;
    cin>>n;
    long long l=0;
    long long a=999;
    while(a>=100)
    {
      long long b,db;
      if(a%11==0)
      {
        b=999;
        db=1;
      }
      else
      {
        b=990;
        db=11;
      }
      while(b>=a)
      {
        long long temp=a*b;
        if(temp>=n)
        {
          b-=db;
          continue;
        }
          
          if(temp<=l)
            break;
          stringstream ss;
          ss<<temp;
          string s,s1;
          s=ss.str();
          s1=s;
          reverse(s1.begin(),s1.end());
          if(s==s1)
            l=temp;
          b-=db;
      }
    a--;
    }
    cout<<l<<endl;
  }
return 0;
}