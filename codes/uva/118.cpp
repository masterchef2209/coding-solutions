#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>

int X,Y;

int arr[52][52];
char news[4]={'N','E','S','W'};

inline bool ingrid(ii &a)
{
	return a.first>=0 && a.second>=0 && a.first<=X && a.second<=Y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>X>>Y;
	int x,y;
	char dir;
	while(cin>>x>>y>>dir)
	{
		string seq;
		cin>>seq;
		int dd;
		switch(dir)
		{
			case 'N':dd=0;
					break;
			case 'E':dd=1;
					break;
			case 'S':dd=2;
					break;
			case 'W':dd=3;
					break;
		}
		for(int i=0;i<seq.size();i++)
		{
			if(seq[i]=='R')
			{
				dd=(dd+1)%4;
			}
			else if(seq[i]=='L')
			{
				dd=dd-1;
				if(dd==-1)
				{
					dd=3;
				}
			}
			else if(seq[i]=='F')
			{
				int tx=x,ty=y;
				switch(dd)
				{
					case 0:ty=y+1;break;
					case 1:tx=x+1;break;
					case 2:ty=y-1;break;
					case 3:tx=x-1;break;
				}
        ii pp=make_pair(tx,ty);
				if(!ingrid(pp))
				{
					if(arr[x][y]==0)
					{
						arr[x][y]=1;
						cout<<x<<" "<<y<<" "<<news[dd]<<" "<<"LOST"<<endl;
						break;
					}
				}
				else
				{
					x=tx;
					y=ty;
				}
			}
			if(i==seq.size()-1)
			{
				cout<<x<<" "<<y<<" "<<news[dd]<<endl;
			}
		}
	}
return 0;
}