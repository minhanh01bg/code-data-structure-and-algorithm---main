#include<bits/stdc++.h>
using namespace std;
#define Nothing					"mikey"
#define Nothing					"mikey"
#define Nothing					"mikey"
#define Nothing					"mikey"
#define Nothing					"mikey"
#define run() int t;cin>>t;while(t--)
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long
/*---------------------------------------------------------------*/
int p = 1e9 + 7;
main() {
    faster()
    run() {
        int n;    cin >> n;
        ll dp[102][102];
        memset(dp, 0, sizeof(dp));
        FOR(i, 0, 9)
            dp[i][1]=1;
        FOR(i, 2, n)
            FOR(j, 0, 9)
                FOR(k, 0, j)
                    dp[j][i] += dp[k][i-1];
                
        ll sum=0;
        FOR(i, 0, 9)  
            sum += (dp[i][n] % p);
        cout<<sum%p<<endl;
    }
    return 0;
}
