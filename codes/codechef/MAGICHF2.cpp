#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k,k1;
		cin>>n>>k;
    k1=k;
    if(n != 2)
            while(k > 0){
                if(n == 2){
                    n = 1;
                    break;
                }

                if(n % 2 == 0)
                    if((n / 2) % 2 > 0 and k1 == k)
                        n = n / 2 + 1;
                    else n = n / 2;
                else n = n / 2 + 1;
                k--;
            }
    cout<<fixed<<setprecision(8)<<1/(double)n<<endl;
	}
return 0;
}