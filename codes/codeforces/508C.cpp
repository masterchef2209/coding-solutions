#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  multiset<int> p1,p2;
  for(int u=0;u<n;u++)
  {
    int temp;
    cin>>temp;
    p1.insert(temp);
  }
  for(int u=0;u<n;u++)
  {
    int temp;
    cin>>temp;
    p2.insert(temp);
  }
  long long x=0,y=0;
  int q=0;
  while(!p1.empty() || !p2.empty())
  {
    if(!(q&1))
    {
      multiset<int> ::iterator it1,it2;
      int my=INT_MIN;
      int your=INT_MIN;
      if(!p1.empty())
      {
        it1=p1.end();
        --it1;
        my=*it1; 
      }
      if(!p2.empty())
      {
        it2=p2.end();
        --it2;
        your=*it2;
      }
      if(my>=your)
      {
        x+=my;
        multiset<int>:: iterator tem=p1.end();
        --tem;
        p1.erase(tem);
      }
      else
      {
        multiset<int>:: iterator tem=p2.end();
        --tem;
        p2.erase(tem);
      }
      //cout<<my<<" "<<your<<endl;
    }
    else
    {
      multiset<int> ::iterator it1,it2;
      int my=INT_MIN;
      int your=INT_MIN;
      if(!p2.empty())
      {
        it2=p2.end();
        --it2;
        my=*it2;
      }
      if(!p1.empty())
      {
        it1=p1.end();
        --it1;
        your=*it1;
      }
      if(my>=your)
      {
        y+=my;
        multiset<int>:: iterator tem=p2.end();
        --tem;
        p2.erase(tem);
      }
      else
      {
        multiset<int>:: iterator tem=p1.end();
        --tem;
        p1.erase(tem);
      }
      //cout<<my<<" "<<your<<endl;
    }
    q++;
    //cout<<x<<" "<<y<<endl;
  }
  cout<<x-y;
return 0;
}