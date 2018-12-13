#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	int t=0;
	if(a<=1 && b<=1)
    {
      cout<<t<<endl;
      exit(0);
    }
	while(a!=0 && b!=0)
	{
		if(a<=b)
		{
			while(b>2)
			{
				a+=1;
				b-=2;
				t+=1;
        //cout<<a<<" "<<b<<endl;
			}
		}
		else if(b<a)
		{
			while(a>2)
			{
				b+=1;
				a-=2;
				t+=1;
        //cout<<a<<" "<<b<<endl;
			}
		}
    if(a<=2 && b<=2)
    {
      t+=1;
      break;
    }
	}
	cout<<t<<endl;
return 0;
}