/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
typedef int ll;
 
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
 
double PI=3.1415926535897932384626;
 
//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}
 
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;
 
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)
 
//struct custom_hash {
//    static uint64_t splitmix64(uint64_t x) {
//        // http://xorshift.di.unimi.it/splitmix64.c
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//    size_t operator()(uint64_t x) const {
//        static const uint64_t FIXED_RANDOM = 
//            chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};
 
#define fi first
#define se second
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll l=0;
		ll r=s.size()-1;
		while(l<r)
		{
			if(s[l]==s[r])
			{
				l++;
				r--;
			}
			else
			{
				break;
			}
		}
		string pref=s.substr(0,l);
		string suf=s.substr(r+1,l);
		string s1=s.substr(l,r-l+1);
		//cout<<s1<<endl;
		ll n=s1.size();
		vector<int> d1(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
    		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    		while (0 <= i - k && i + k < n && s1[i - k] == s1[i + k]) {
        		k++;
    		}
    		d1[i] = k--;
    		if (i + k > r) {
        		l = i - k;
        		r = i + k;
    		}
		}
		vector<int> d2(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
    		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
   			while (0 <= i - k - 1 && i + k < n && s1[i - k - 1] == s1[i + k]) {
        		k++;
    		}
    		d2[i] = k--;
    		if (i + k > r) {
        		l = i - k - 1;
        		r = i + k ;
    		}
		}
// 		for(ll i=0;i<n;i++)
// 		{
// 		    cout<<d1[i]<<" ";
// 		}
// 		cout<<endl;
// 		for(ll i=0;i<n;i++)
// 		{
// 		    cout<<d2[i]<<" ";
// 		}
// 		cout<<endl;
		ll len1=0;
		ll pos=0;
		ll lol=0;
		ll fl=0;
		ll tim=0;
		for(ll i=n/2;i<n;i++)
		{
		    if(fl==1)
		    {
		        tim++;
		    }
		    if(tim>=5)
		        break;
			ll diffsuf=n-i;
			//cout<<diffpref<<" "<<diffsuf<<endl;
					if(diffsuf<=d1[i])
					{
						ll len=diffsuf+(diffsuf-1);
						if(len>len1)
						{
							len1=len;
							pos=i-(diffsuf-1);
							fl=1;
						}
					}
					if(diffsuf<=d2[i])
					{
						ll len=diffsuf*2;
						if(len>len1)
						{
							len1=len;
							pos=i-diffsuf;
							fl=1;
						}
					}	
		}
		ll stt;
		fl=0;
		tim=0;
		if(n&1)
		{
		    stt=n/2;
		}
		else
		{
		    stt=n/2-1;
		}
		for(ll i=stt;i>=0;i--)
		{
		    if(fl==1)
		    {
		        tim++;
		    }
		    if(tim>=5)
		        break;
			ll diffpref=i+1;
			//cout<<diffpref<<" "<<diffsuf<<endl;
					if(diffpref<=d1[i])
					{
						ll len=diffpref+(diffpref-1);
						if(len>len1)
						{
							len1=len;
							pos=0;
							fl=1;
						}
					}
					if(diffpref<=d2[i+1])
					{
						ll len=diffpref*2;
						if(len>len1)
						{
							len1=len;
							pos=0;
							fl=1;
						}
					}
		}
		string mid=s1.substr(pos,len1);
		cout<<(pref+mid+suf)<<endl;
	}
    return 0;
}
 
 
//252908XL