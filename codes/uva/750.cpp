#include<bits/stdc++.h>
using namespace std;

char sol[100][10];
char temp[10];
bitset<10>row,rd,ld;
int length;

void solve(int c)
{
    if(c==8)
    {
        temp[8]=0;
        strcpy(sol[length++],temp);
        return;
    }
    for(int r=0;r<8;r++)
    {
        if(!row[r] && !rd[r-c+8] && !ld[r+c])
        {
            row[r]=rd[r-c+8]=ld[r+c]=1;
            temp[c]='1'+r;
            solve(c+1);
            row[r]=rd[r-c+8]=ld[r+c]=0;
        }
    }
}

int main()
{
    length=0;
    solve(0);
    int t;
    cin>>t;
    bool blank=false;
    
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        int cases=0;
        
        if(blank)   cout<<endl;
        blank=true;
        
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8\n" << endl;
        
        for ( int i = 0; i < length; i++ ) {
            if ( sol [i] [c - 1] == r + '0' ) {
                printf ("%2d      ", ++cases);
                printf ("%c", sol [i] [0]);
                for ( int j = 1; j < 8; j++ )
                    printf (" %c", sol [i] [j]);
                printf ("\n");
            }
        }
    }
    return 0;
}