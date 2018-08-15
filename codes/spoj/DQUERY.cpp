#include<bits/stdc++.h>
using namespace std;
//not accepted
//tle
int main()
{
  int n;
  cin>>n;
  vector<int> bag(n+1);
  for(int i=1;i<=n;i++)
  {
    cin>>bag[i];
  }
  int q;
  cin>>q;
  while(q--)
  {
    int i,j;
    cin>>i>>j;
    set<int> temp;
    for(int k=i;k<=j;k++)
    {
      temp.insert(bag[k]);
    }
    cout<<temp.size()<<endl;
  }
return 0;
}
