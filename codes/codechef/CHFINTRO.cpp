#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,r;
	cin>>N>>r;
	for(int u=0;u<N;u++)
	{
		int R;
		cin>>R;
		if(R>=r)
			cout<<"Good boi"<<endl;
		else
			cout<<"Bad boi"<<endl;
	}
return 0;
}