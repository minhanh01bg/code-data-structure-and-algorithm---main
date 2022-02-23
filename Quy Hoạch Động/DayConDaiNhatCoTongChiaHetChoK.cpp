#include <bits/stdc++.h>
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
using namespace std;

/*--------------------------------------------*/

main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    run() {
        int n, k, a;
        cin >> n >> k;
        int dp[n + 1][k];
        dp[0][0] = 0;
        FOR(i, 1, k - 1)
            dp[0][i] = 0;
        
        FOR(i, 1, n){
            cin >> a;
            a %= k;
            FOR(j, 0, k - 1)
                dp[i][j] = max(dp[i-1][j], dp[i - 1][(j + a) % k] + 1); 
        }
        cout << dp[n][0] << endl;
    }
}