#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
  cout<<min(arr[n-2]-arr[0],arr[n-1]-arr[1]);
return 0;
}