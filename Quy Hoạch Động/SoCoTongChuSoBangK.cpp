#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EL printf("\n")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a,x) memset(a, x, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define run() int t;cin>>t;while(t--)
#define endl "\n"
/*--------------------------------------------*/
const ll p = 1e9+7;

ll dp[101][50001];
// i số chữ số
// tổng là j
void mi(){
    for(int i = 0;i < 101; i++)
        dp[i][0] = 0;
    
    for(int i = 0;i < 50001; i++)
        dp[0][i] = 0;
    
    for(int i = 1;i <= 9; i++)
        dp[1][i] = 1;
    
    for(int i = 1;i < 101; i++)
        for(int j = 0;j <= 9; j++)
            for(int k = j;k < 50001; k++)
                dp[i][k] = (dp[i][k] % p + dp[i - 1][k - j] % p) % p;    
}
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    mi();
    run(){
        int n,m;
        cin >> n >> m;
        cout << dp[n][m] << endl;    
    }   
}