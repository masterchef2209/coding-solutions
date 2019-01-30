#include<bits/stdc++.h>
using namespace std;

long long compute(long long a,long long b,int c)
{
    switch(c)
    {
        case 0: return a+b;
        case 1:return b-a;
        case 2:return a*b;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long arr[5];
	for(int i=0;i<5;i++)
	    cin>>arr[i];
	while(1)
	{
		int flag=0;
		if(arr[0]==0 && arr[1]==0 && arr[2]==0 && arr[3]==0 && arr[4]==0)
			break;
		sort(arr,arr+5);
		do
		{
			for(int p=0;p<3;p++)
			for(int q=0;q<3;q++)
				for(int r=0;r<3;r++)
					for(int s=0;s<3;s++)
					{
						if(compute(arr[4],(compute(arr[3],(compute(arr[2],(compute(arr[1],arr[0],p)),q)),r)),s)==23)
						{
							flag=1;
							//cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
							goto label;
						}
					}
		}while(next_permutation(arr,arr+5));
		label:;
		if(flag)
			cout<<"Possible"<<endl;
		else
			cout<<"Impossible"<<endl;
		for(int i=0;i<5;i++)
	        cin>>arr[i];
	}
return 0;
}