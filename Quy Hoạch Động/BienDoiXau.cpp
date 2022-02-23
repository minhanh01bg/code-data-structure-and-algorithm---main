#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EL printf("\n")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a) memset(a, 0, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define run() int t;cin>>t;while(t--)
#define endl "\n"
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//xâu con không chung dài nhất
int main(){
    fast()
    string a,b;
    run(){
        cin>>a>>b;
        int n=a.size(),m=b.size();
        int lis[n+1][m+1];
        FOR(i,0,n){
            FOR(j,0,m){
                if(j==0)
                    lis[i][j]=i;
                else if(i==0) 
                    lis[i][j]=j;
                else if(a[i-1]==b[j-1])
                    lis[i][j]=lis[i-1][j-1];
                else lis[i][j]=1+min(lis[i-1][j],min(lis[i][j-1],lis[i-1][j-1]));
            }
        }
        cout<<lis[n][m]<<endl;
    }
}