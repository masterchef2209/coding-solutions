#include<bits/stdc++.h>
using namespace std;
#define MM 1000000007
//not accepted
int gcd(int a,int b)
{
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		long long ans=0;
		long long l,r;
		cin>>l>>r;
    int arr[r-l+1];
    long long k=0;
    for(long long i=l;i<=r;i++,k++)
    {
      int u=0;
      long long p=i;
      while(p>0)
        {
          int r=p%10;
          u+=r;
          p=p/10;
        }
        arr[k]=u;
    }
		for(long long i=0;i<r-l;i++)
		{
			for(long long j=i+1;j<r-l+1;j++)
			{
        //cout<<arr[i]<<" "<<arr[j]<<endl;
				if(gcd(arr[i],arr[j])==1)
				{
					ans=(ans+1)%MM;
				}
			}
		}
		cout<<ans<<endl;
	}
return 0;
}