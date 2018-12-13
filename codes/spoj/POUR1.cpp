#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}
int pour(int A,int B,int C){
int move=1,a=A,b=0,tfr;
while(a!=C && b!=C){
           tfr=min(a,B-b);
           b+=tfr;
           a-=tfr;
           move++;
           if(a==C || b==C)
                   break;
           if(a==0){
                    a=A;
                    move++;
           }
           if(b==B){
                b=0;
                move++;
           }
     }
     return move;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(c==0)
		{
			cout<<0<<endl;
			continue;
		}
		if(a==c || b==c)
		{
			cout<<1<<endl;
			continue;
		}
		if(a==0 || b==0)
		{
			cout<<-1<<endl;
			continue;
		}
		int flag=0;
		if(c>a && c>b)
			flag=1;
		int z=gcd(a,b);
		if(c%z!=0)
			flag=1;
		if(flag==1)
		{
			cout<<-1<<endl;
			continue;
		}
		cout<<min(pour(a,b,c),pour(b,a,c))<<endl;
	}
return 0;
}