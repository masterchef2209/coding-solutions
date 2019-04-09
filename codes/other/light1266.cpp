#include<iostream>
#include<vector>
#define vi vector<int>
using namespace std;

vector< vi >tree(1005,vector<int>(1005,0));
bool flag[1005][1005];

int query(int x,int y)
{
	int sum=0;
	int y1;
	while(x>0)
	{
		y1=y;
		while(y1>0)
		{
			sum+=tree[x][y1];
			y1-=(y1&-y1);
		}
		x-=(x&-x);
	}
	return sum;
}

void update(int x,int y,int val)
{
	int y1;
	while(x<=1001)
	{
		y1=y;
		while(y1<=1001)
		{
			tree[x][y1]+=val;
			y1+=(y1&-y1);
		}
		x+=(x&-x);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int u=1;u<=t;u++)
	{
		for(int i=0;i<=1001;i++)
		{
			for(int j=0;j<=1001;j++)
			{
			    flag[i][j]=false;
				tree[i][j]=0;
			}
		}
		printf("Case %d:\n",u);
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int status;
			scanf("%d",&status);
			if(status==0)
			{
				int x,y;
				scanf("%d %d",&x,&y);
				x++;y++;
				if(!flag[x][y])
				{
				    flag[x][y]=true;
					update(x,y,1);
				}
			}
			else if(status==1)
			{
				int x1,y1,x2,y2;
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				x1++;y1++;x2++;y2++;
				printf("%d\n",query(x2,y2)-query(x1-1,y2) -query(x2,y1-1) +query(x1-1,y1-1));
			}
		}
	}
    return 0;
}