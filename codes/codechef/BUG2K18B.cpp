#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int hi,hf,mi,mf;
		char g1,g2;
		int d1,d2;
		cin>>hi>>g1>>mi>>d1>>hf>>g2>>mf>>d2;
		int y1=hi*60+mi+d1;
		int y2=hf*60+mf+d2;
		int time=y2-y1;
		if(time<0)
		{
			cout<<"No"<<endl;
		}
		else
			cout<<"Yes"<<endl;
	}
return 0;
}