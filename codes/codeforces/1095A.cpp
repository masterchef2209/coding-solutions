#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  int count=-1;
  for(int i=0;i<s.length();i++)
  {
    cout<<s[i];
    count++;
    int t=count;
    while(t--)
      i++;
  }
return 0;
}