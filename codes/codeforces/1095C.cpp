#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	long long n,m;
	cin>>n>>m;
  if(n<m)
  {
    cout<<"NO";
    return 0;
  }
	multiset<long long>f;
	long long temp=n;
	long long y=0,z=0;
	while(temp>0)
	{
		if(temp&1)
		{
      z++;
			f.insert(1<<y);
		}
		temp>>=1;
		y++;
	}
  if(z>m)
  {
    cout<<"NO";
    return 0;
  }
	while(z<m)
  {
    auto it=f.end();
    --it;
    long long x=*it;
    if(x==1)
    {
      cout<<"NO";
      return 0;
    }
    f.erase(it);
    f.insert(x/2);
    f.insert(x/2);
    z++;
  }
  if(f.size()==m)
  {
    cout<<"YES"<<endl;
    for(auto x:f)
    {
      cout<<x<<" ";
    }
  }
  else
  {
    cout<<"NO"<<endl;
  }
return 0;
}