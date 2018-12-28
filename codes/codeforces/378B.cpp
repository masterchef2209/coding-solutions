#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int n;
	cin>>n;
	vector<long long>A,B;
	vector<long long>flagA(n,0);
	vector<long long>flagB(n,0);
	vector<long long>C;
	for(int i=0;i<n;i++)
	{
		long long a,b;
		cin>>a>>b;
		A.push_back(a);
		B.push_back(b);
		C.push_back(a);
		C.push_back(b);
		if(i<n/2)
		{
			flagA[i]|=1;
			flagB[i]|=1;
		}
	}
	sort(C.begin(),C.end());
	for(int i=0;i<A.size();i++)
	{
		if(binary_search(C.begin(),C.begin()+n,A[i]))
			flagA[i]|=1;
	}
	for(int i=0;i<B.size();i++)
	{
		if(binary_search(C.begin(),C.begin()+n,B[i]))
			flagB[i]|=1;
	}
	for(int i=0;i<n;i++)
	{
		cout<<flagA[i];
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<flagB[i];
	}
	cout<<endl;
return 0;
}