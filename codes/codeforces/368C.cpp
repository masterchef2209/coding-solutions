#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int x[s.size()+1]={0},y[s.size()+1]={0},z[s.size()+1]={0};
	x[0]=0;
	y[0]=0;
	z[0]=0;
	for(int i=0;i<s.size();i++)
	{
		switch(s[i])
		{
			case 'x':x[i+1]=x[i]+1;
			y[i+1]=y[i];
			z[i+1]=z[i];
			break;
			case 'y':y[i+1]=y[i]+1;
			x[i+1]=x[i];
			z[i+1]=z[i];
			break;
			case 'z':z[i+1]=z[i]+1;
			x[i+1]=x[i];
			y[i+1]=y[i];
			break;	
		}
	}
	int m;
	cin>>m;
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		int cX,cY,cZ;
		cX=x[r]-x[l-1];
		cY=y[r]-y[l-1];
		cZ=z[r]-z[l-1];
		int k=(r-l+1);
		if(k<3)
			cout<<"YES"<<endl;
		else
		{
			if(cX>0 && cY>0 && cZ>0)
			{
				if(k%3==0 && cX==cY && cX==cZ && cY==cZ)
					cout<<"YES"<<endl;
				else if(k%3==1 && ( (cX==cY+1 && cX==cZ+1) || (cY==cX+1 && cY==cZ+1) || (cZ==cY+1 && cZ==cX+1) ) )
					cout<<"YES"<<endl;
				else if(k%3==2 && ( (cX==cY-1 && cX==cZ-1) || (cY==cX-1 && cY==cZ-1) || (cZ==cY-1 && cZ==cX-1) ) )
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}

	return 0;
}