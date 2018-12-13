#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a=1;
	int b=pow(n,2);
	while(a<b)
	{
		cout<<a<<" "<<b<<endl;
		a++;
		b--;
	}
return 0;
}