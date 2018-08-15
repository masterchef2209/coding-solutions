#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int l;
  cin>>l;
  for(int i=0;i+l-1<n;i++)
  {
    int *p;
    p=max_element(arr+i,arr+i+l);
    cout<<*p<<" ";
  }
return 0;
}
