#include<iostream>
#include<vector>
using namespace std;

vector<int>tree(100005);
vector<int>arr(100005);
int n,q;

void update(int pos,int val)
{
	while(pos<=n)
	{
		tree[pos]+=val;
		pos+=(pos&-pos);
	}
}

int query(int pos)
{
	int sum=0;
	while(pos>=1)
	{
		sum+=tree[pos];
		pos-=(pos&-pos);
	}
	return sum;
}

int readSingle(int pos)
{
	int sum=tree[pos];
	if(pos>1)
	{
		int z=pos-(pos&-pos);
		pos--;
		while(pos!=z)
		{
			sum-=tree[pos];
			pos-=(pos&-pos);
		}
	}
	return sum;
}

int main(){
	int u;
	scanf("%d",&u);
	for(int t=1;t<=u;t++)
	{
		cout<<"Case "<<t<<":"<<endl;
		scanf("%d %d",&n,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			tree[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			update(i,arr[i]);
		}
		while(q--)
		{
			int status;
			scanf("%d",&status);
			if(status==1)
			{
				int pos;
				scanf("%d",&pos);
				pos++;
				int temp=readSingle(pos);
				printf("%d\n",temp);
				update(pos,-temp);
			}
			else if(status==2)
			{
				int pos,val;
				scanf("%d %d",&pos,&val);
				pos++;
				update(pos,val);
			}
			else if(status==3)
			{
				int l,r;
				scanf("%d %d",&l,&r);
				l++;
				r++;
				if(l==1)
				    printf("%d\n",query(r));
				else 
				    printf("%d\n",query(r)-query(l-1));
			}
		}
	}
    return 0;
}