#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,k,A,B;
vector<int>avengers;
map<int,int> mmap;

int func(int i,int j)
{
    if(i>j)
        return 0;
	if(i==j)
	{
	    int sum1=0;
		if(mmap.find(i)!=mmap.end())
		{
			sum1=B*mmap[i];
		}
		else
		{
			sum1=A;
		}
		//cout<<i<<" "<<j<<" "<<sum1<<endl;
		return sum1;
	}
	auto st=mmap.lower_bound(i);
	auto en=mmap.lower_bound(j);
	if(en->first == j)
		en++;
	int sum=0;
	while(st!=en)
	{
		sum+=(st->second);
		st++;
	}
	int aans=0;
	if(sum==0)
		aans= A;
	else
	    aans=min(B*sum*(j-i+1),func(i,(i+j)/2)+func((i+j)/2+1,j) );
	//cout<<i<<" "<<j<<" "<<aans<<endl;
	return aans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k>>A>>B;
	for(int i=0;i<k;i++)
	{
		int temp;
		cin>>temp;
		avengers.emplace_back(temp-1);
		mmap[temp-1]++;
	}
	sort(avengers.begin(),avengers.end());
	cout<<func(0,pow(2,n)-1);
return 0;
}