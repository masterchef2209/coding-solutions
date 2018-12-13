#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a,b,c;
  char A,B,C;
  char e;
  cin>>A>>B>>e>>C;
  a=A-'0';
  b=B-'0';
  c=C-'0';
  while(a!=0 || b!=0 || c!=0)
  {
    long long z=a*pow(10,c+1)+b*pow(10,c);
    //cout<<z<<endl;
    long long temp=z,temp1;
    for(int i=0;;i++)
    {
      temp1=temp;
      temp=temp-pow(2,i);
      if(temp<=0)
        break;
    }
    int ans=-1;
    while(temp1--)
    {
      ans+=2;
    }
    cout<<ans<<endl;
    cin>>A>>B>>e>>C;
    a=A-'0';
    b=B-'0';
    c=C-'0';
  }
  return 0;
}