#include<bits/stdc++.h>
using namespace std;
//not accepted
bool func(long n)
{
	if(n==3)
		return true;
	if(n==4)
		return false;
	for(int i=2;i*i<n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int main()
{
	int c;
	cin>>c;
	while(c--)
	{
		long n;
		cin>>n;
    if(n<=2)
      cout<<"Yes"<<endl;
    else if(n%2==0 && sqrt(n/2)==(int)sqrt(n/2))
    {
      cout<<"Yes"<<endl;
    }
    else
    {
      if(func(n) && n%4==1)
			  cout<<"Yes"<<endl;
		  else
			  cout<<"No"<<endl;
    }
	
	}
return 0;
}