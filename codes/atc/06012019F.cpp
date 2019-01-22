#include<bits/stdc++.h>
using namespace std;
 
 int dp[3005][3005];

int main()
{
    string s,t;
    cin>>s>>t;
    for(int i=0;i<=s.size();i++)
    {
        dp[i][t.size()]=0;
    }
    for(int i=0;i<=t.size();i++)
    {
        dp[s.size()][i]=0;
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        for(int j=t.size()-1;j>=0;j--)
        {
            if(s[i]==t[j])
            {
                dp[i][j]=1+dp[i+1][j+1];
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    
    int i=0,j=0;
    while(i<s.size() && j<t.size())
    {
        if(s[i]==t[j])
        {
            cout<<s[i];
            i++;j++;
        }
        else if(dp[i+1][j]>dp[i][j+1])
        {
            i++;
        }
        else if(dp[i][j+1]>=dp[i+1][j])
        {
            j++;
        }
    }
    
return 0;
}