#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int fhalf=0,fquarter=0,ft34th=0;
	while(n--)
	{
		string s;
		cin>>s;
		if(s=="1/4")
		{
			fquarter++;
		}
		else if(s=="1/2")
		{
			fhalf++;
		}
		else if(s=="3/4")
		{
      ft34th++;
		}
	}
	//cout<<fhalf<<endl<<fquarter<<endl<<ft34th;
  if(fquarter>=ft34th)
    fquarter=fquarter-ft34th;
  else
    fquarter=0;
  if(fhalf&1==1)
  {
    if(fquarter>=2)
     { fquarter-=2;
      fhalf+=1;}
    else{
      fquarter=0;
      fhalf+=1;
    }
  }
  fhalf=fhalf/2;
  int leftover=fquarter%4;
  fquarter=fquarter/4;
  int ans=ft34th+fhalf+fquarter+1;
  if(leftover!=0)
    ans+=1;
  cout<<ans;
return 0;
}
