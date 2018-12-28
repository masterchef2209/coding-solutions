#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long e,f,s,m,e1,f1,s1,m1;
	cin>>e>>f>>s>>m>>e1>>f1>>s1>>m1;
	while(s!=-1)
	{
			long long u=max({ceil(e/(double)e1),ceil(f/(double)f1),ceil(s/(double)s1),ceil(m/(double)m1)});
    		cout<<e1*u-e<<" "<<f1*u-f<<" "<<s1*u-s<<" "<<m1*u-m<<endl;
	cin>>e>>f>>s>>m>>e1>>f1>>s1>>m1;
	}
}