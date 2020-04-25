#include<bits/stdc++.h>
using namespace std;

#define ll long long

class ThreeNeighbors
{
    public:
    vector<string> construct(int N)
    {
        string blue(50,'.');
        vector<string>ret;
        for(ll i=0;i<50;i++)
        {
            ret.emplace_back(blue);
        }
        for(ll i=0;i<50;i+=3)
        {
            ret[0][i]='X';
            ret[49][i]='X';
        }
        if(N&1)
        {
            ret[47][0]='X';
            ret[48][0]='X';
            N--;
        }
        N/=2;
        ll xx=N+1;
        ll fl=0;
        for(ll i=48;i>0;i-=3)
        {
            if(fl)
                break;
            for(ll j=1;j<49;j++)
            {
                if(xx>0)
                {
                    ret[j][i]='X';
                    xx--;
                    if(xx==0 && j==48)
                    {
                        ret[49][i]='.';
                    }
                }
                else
                {
                    fl=1;
                    break;
                }
            }
            if(fl)
                break;
        }
        if(xx>0)
        {
            ll lol=1;
            while(xx>0)
            {
                ret[lol][0]='X';
                lol++;
                xx--;
            }
            ret[lol][0]='X';
        }
        return ret;
    }
};