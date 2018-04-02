#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x1,y1,r1,x2,y2,r2;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		double d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		double r=(r1>=r2)?(r1-r2):(r2-r1);
		if(r>d)
			cout<<"I\n";
		else if(r==d)
			cout<<"E\n";
		else 
			cout<<"O\n";
	}	
return 0;
}