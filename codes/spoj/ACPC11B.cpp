#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n1,n2;
		cin>>n1;
		vector<int> arr1(n1);
		for(int i=0;i<n1;i++)
		{
			cin>>arr1[i];
		}
		cin>>n2;
		vector<int> arr2(n2);
		for(int i=0;i<n2;i++)
		{
			cin>>arr2[i];
		}
		sort(arr1.begin(),arr1.end());
		sort(arr2.begin(),arr2.end());
		int m=INT_MAX;
		for(int i=0;i<n2;i++)
		{
			vector<int>::iterator it=lower_bound(arr1.begin(),arr1.end(),arr2[i]);
      int x;
      if(it==arr1.end())
      {
        x=arr2[i]-*prev(it);
      }
      else if(it==arr1.begin())
      {
        x=*it-arr2[i];
      }
      else
      {
        x=min(*it-arr2[i],arr2[i]-*prev(it));
      }
      if(x<m)
			{
				m=x;
			}
		}
		cout<<m<<endl;
	}
return 0;
}