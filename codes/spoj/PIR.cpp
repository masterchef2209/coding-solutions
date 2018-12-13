#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long double u,v,w,W,V,U;
		cin>>u>>v>>w>>W>>V>>U;
		long double u1=pow(v,2)+pow(w,2)-pow(U,2);
		long double v1=pow(u,2)+pow(w,2)-pow(V,2);
		long double w1=pow(v,2)+pow(u,2)-pow(W,2);
		long double volume=sqrt(4*pow(u,2)*pow(v,2)*pow(w,2)-pow(u,2)*pow(u1,2)-pow(v,2)*pow(v1,2)-pow(w,2)*pow(w1,2)+u1*v1*w1)/12;
		cout<<fixed<<setprecision(4)<<volume<<endl;
	}
return 0;
}