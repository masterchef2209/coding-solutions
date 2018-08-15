#include<bits/stdc++.h>
using namespace std;

int main()
{
	long n,h,a,b;
	cin>>n>>h>>a>>b;
	int k;
	cin>>k;
	while(k--)
	{
		long ti,fi,tf,ff;
		cin>>ti>>fi>>tf>>ff;
		long long ans=abs(tf-ti);
    if(ti!=tf)
    {
		  if(fi<a && ff<a)
    		{
     			 ans+=((a-fi)+(a-ff));
   		}
   		 else if(fi>b && ff>b)
    		{
      			ans+=((fi-b)+(ff-b));
    		}
    		else
    		{
      			ans+=((long long)abs(ff-fi));
    		}
    }
    else
    {
        ans+=((long long)abs(ff-fi));
    }
    		cout<<ans<<endl;
	}
return 0;
}
