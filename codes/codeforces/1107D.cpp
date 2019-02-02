#include<bits/stdc++.h>
using namespace std;
#define N 5205

int arr[N][N];

void parse_char(int u,int v,char buf)
{
	char num=buf;
	int index=-1;
	if(isdigit(num))
	{
		index=num-'0';
	}
	else
	{
		index=num-'A'+10;
	}
	int yo=3;
	//cout<<index<<endl;
	while(yo>=0)
	{
	    arr[u][v*4+yo]=index&1;
	    yo--;
	    index>>=1;
		//cout<<temp;
	}
//	cout<<" ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	char buf[n];
	for(int u=0;u<n;u++)
	{
		cin>>buf;
		for(int v=0;v<n/4;v++)
		{
			parse_char(u,v,buf[v]);
		}
		//cout<<endl;
	}
// 	for(int i=0;i<n;i++)
// 	{
// 	    for(int j=0;j<n;j++)
// 	    {
// 	        cout<<arr[i][j];
// 	    }
// 	    cout<<endl;
// 	}
	int gc=n;
    
    for(int u=0;u<n;u++)
    {
        int j=0;
        while(j<n)
         {
         	int i=j;
            while(i<n && j<n && arr[u][i]==arr[u][j])
            {
                i++;
            }
            gc=__gcd(gc,i-j);
            j=i;
        }
    }
    
    for(int u=0;u<n;u++)
    {
        int j=0;
        while(j<n)
         {
         	int i=j;
            while(i<n && j<n && arr[i][u]==arr[j][u])
            {
                i++;
            }
            gc=__gcd(gc,i-j);
            j=i;
        }
    }
    
    cout<<gc;

return 0;
}