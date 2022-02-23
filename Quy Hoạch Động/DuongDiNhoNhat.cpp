#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i > (b); i--)
#define REPD(i, a, b) for (int i = (a); i >= (b); i--)
#define TR(it, a) for (typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define BEGIN \
    int t;    \
    cin >> t; \
    while (t--)
#define reset(x) memset(x, 0, sizeof((x)))
#define SZ(a) (int((a).size()))
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
const int N = 100005;
using namespace std;
#define mo 1000000007

int main()
{
    FAST
        BEGIN
    {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1];
        REP(i, 1, n)
        {
            REP(j, 1, m)
            cin >> a[i][j];
        }
        int dp[n][m];
        dp[1][1] = a[1][1];
        REP(i, 1, n)
        {
            REP(j, 1, m)
            {
                if (i == 1 && j == 1)
                    continue;
                else if (i == 1)
                    dp[i][j] = a[i][j] + dp[i][j - 1];
                else if (j == 1)
                    dp[i][j] = a[i][j] + dp[i - 1][j];
                else
                    dp[i][j] = a[i][j] + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}