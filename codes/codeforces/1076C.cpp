#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int d;
		cin>>d;
		if(d==1||d==2||d==3)
			cout<<"N"<<endl;
    else if(d==0)
      cout<<"Y 0.000000000 0.000000000\n";
    else if(d==4)
      cout<<"Y 2.000000000 2.000000000\n";
		else
		{
			double lo=0;
			double hi=d;
			while((hi-lo)>10e-9)
			{
				double mid=(lo+hi)/2;
				double temp=mid+d/mid-d;
				if(temp<=10e-9)
					lo=mid;
				else
					hi=mid;
			}
			cout<<"Y "<<fixed<<setprecision(9)<<lo<<" "<<d/lo<<endl;
		}
	}
return 0;
}