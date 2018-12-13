#include<bits/stdc++.h>
using namespace std;


int main()
{
  vector<int>A,B,C,D;
  unordered_map<int ,int> mm;
	int n;
	cin>>n;
  mm.reserve(2*n*n);
	while(n--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	int count=0;
  for(int i=0;i<C.size();i++)
  {
    for(int j=0;j<D.size();j++)
    {
      int x=C[i]+D[j];
      mm[x]++;
    }
  }
  for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B.size();j++)
		{
			long long sum1=A[i]+B[j];
			if(mm.find(-sum1)!=mm.end())
      {
        count+=mm[-sum1];
      }
		}
	}
	cout<<count<<endl;
return 0;
}