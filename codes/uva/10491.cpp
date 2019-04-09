#include<bits/stdc++.h>
using namespace std;

int main()
{
	int ncow,ncar,nshow;
	while(scanf("%d %d %d",&ncow,&ncar,&nshow)!=EOF)
	{
		double T=ncow+ncar;
		double d=T-1-nshow;
		double den=T*d;
		double num=ncar*ncow+(ncar-1)*ncar;
		double ans=num/den;
		cout<<fixed<<setprecision(5)<<ans<<endl;
	}
return 0;
}
