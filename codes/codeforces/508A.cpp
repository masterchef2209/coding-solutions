#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  int arr[26];
  memset(arr,0,sizeof(arr));
  for(int i=0;i<n;i++)
  {
    arr[s[i]-'A']++;
  }
  int j=*min_element(arr,arr+k);
  cout<<j*k;
return 0;
}