#include<bits/stdc++.h>
using namespace std;

void computeLPS(int lps[],string pat,int n)
{
	lps[0]=0;
	for(int i=1;i<n;i++)
	{
		if(pat[i]==pat[lps[i-1]])
		{
			lps[i]=1+lps[i-1];
		}
		else
		{
			lps[i]=0;
		}
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
    vector<int> bag;
		string pat;
		cin>>pat;
		int lps[n];
		computeLPS(lps,pat,n);
		/*for(int i=0;i<n;i++)
		{
			cout<<lps[i]<<endl;
		}*/
    string hay;
    cin>>hay;
    int i=0;
    int j=0;
    int haysize=hay.size();
    while(i<haysize)
    {
      while(i<haysize && hay[i]==pat[j])
      {
        i++;
        j++;
      }
      if(j==n)
      {
          bag.push_back(i-j);
          j=lps[j-1];
      }
      while(i<haysize && hay[i]!=pat[j])
      {
        if(j!=0)
          j=lps[j-1];
        else
          i+=1;
      }
    }
    sort(bag.begin(),bag.end());
    vector<int>::iterator it;
    if(bag.empty())
    {
      cout<<endl<<endl;
      continue;
    }
    for(it=bag.begin();it!=bag.end();it++)
    {
      cout<<*it<<endl;
    }
	}
return 0;
}
