#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define endl "\n"
/**/
/*xem phim*/
int main()
{
    // run(){
    int c, n;
    cin >> c >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int dp[n + 1][c + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= c; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= c; j++)
        {
            if (j >= a[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    cout << dp[n][c] << endl;
    // }
}