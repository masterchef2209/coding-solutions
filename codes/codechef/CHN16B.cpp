#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define Point pair<pair<ll,ll>,ll>
ll n;
//not accepted
ll cross(Point a,Point b,Point c)
{
    return (b.first.x-a.first.x)*(c.first.y-a.first.y)-(b.first.y-a.first.y)*(c.first.x-a.first.x);
}

vector<Point> ConvexHull(vector<Point>&p)
{
    ll sz=0;
    vector<Point>hull(2*n);
    sort(p.begin(),p.end());
    for(ll i=0;i<n;i++)
    {
        while(sz>=2 && cross(hull[sz-2],hull[sz-1],p[i])<=0)
            sz--;
        hull[sz++]=p[i];
    }
    for(ll i=n-2,j=sz+1;i>=0;i--)
    {
        while(sz>=j && cross(hull[sz-2],hull[sz-1],p[i])>=0)
            sz--;
        hull[sz++]=p[i];
    }
    hull.resize(sz-1);
return hull;
}

int main()
{
    cin>>n;
    vector<Point> points,ans;
    for(ll u=0;u<n;u++)
    {
        ll s,w,c;
        cin>>s>>w>>c;
        points.emplace_back(make_pair(make_pair(s,w),c));
    }
    ans=ConvexHull(points);
    long long res=0;
    for(ll i=0;i<ans.size();i++)
    {
        res+=ans[i].second;
    }
    cout<<res;
return 0;
}