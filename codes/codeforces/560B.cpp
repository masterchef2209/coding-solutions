#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int a1,b1,a2,b2,a3,b3;
	cin>>a1>>b1>>a2>>b2>>a3>>b3;
	int flag=0;
	if((b2<=b1) && (b3<=b1) && ((a2+a3)<=a1))
		flag=1;
	else if((a2<=a1) && (a3<=a1) && ((b2+b3)<=b1))
		flag=1;
	else if((a2<=b1) && (a3<=b1) && ((b2+b3)<=a1))
		flag=1;
	else if((b2<=a1) && (b3<=a1) && ((a2+a3)<=b1))
		flag=1;
	else if((b2<=b1) && (a3<=b1) && ((a2+b3)<=a1))
		flag=1;
	else if((a2<=a1) && (b3<=a1) && ((b2+a3)<=b1))
		flag=1;
	else if((a2<=b1) && (b3<=b1) && ((b2+a3)<=a1))
		flag=1;
	else if((b2<=a1) && (a3<=a1) && ((a2+b3)<=b1))
		flag=1;
	
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
return 0;
}