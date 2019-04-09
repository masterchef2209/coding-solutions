
#include <bits/stdc++.h> 
using namespace std; 
#define int long long
// Returns the product of digits of number x 
int product(int x) 
{ 
    int prod = 1; 
    while (x) { 
        prod *= (x % 10); 
        x /= 10; 
    } 
    return prod; 
} 
  
// This function returns the number having 
// maximum product of the digits 
int findNumber(int l, int r) 
{ 
    // Converting both integers to strings 
    string a = to_string(l); 
    string b = to_string(r); 
  
    // Let the current answer be r 
    int ans = r; 
    for (int i = 0; i < b.size(); i++) { 
        if (b[i] == '0') 
            continue; 
  
        // Stores the current number having 
        // current digit one less than current 
        // digit in b 
        string curr = b; 
        curr[i] = ((curr[i] - '0') - 1) + '0'; 
  
        // Replace all following digits with 9 
        // to maximise the product 
        for (int j = i + 1; j < curr.size(); j++) 
            curr[j] = '9'; 
  
        // Convert string to number 
        int num = 0; 
        for (auto c : curr) 
            num = num * 10 + (c - '0'); 
  
        // Check if it lies in range and its product 
        // is greater than max product 
        if (num >= l && product(ans) < product(num)) 
            ans = num; 
    } 
  
    return ans; 
} 
  
// Driver Code 
signed main() 
{ 
    int n;
    cin>>n;
    int l = 1, r = n; 
    int ans=findNumber(l, r);
    int out=1;
    while(ans>0)
    {
        out*=(ans%10);
        ans/=10;
    } 
    cout<<out<<endl;
    return 0; 
} 