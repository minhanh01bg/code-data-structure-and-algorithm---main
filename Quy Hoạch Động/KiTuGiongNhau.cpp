#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i > (b); i--)
#define REPD(i, a, b) for (int i = (a); i >= (b); i--)
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
/*------------------------------------*/
int main()
{
    FAST
        BEGIN
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = a;
        REP(i, 2, n)
        {
            if (i & 1)
                dp[i] = min(dp[i - 1] + a, dp[(i + 1) / 2] + c + b);
            else
                dp[i] = min(dp[i / 2] + c, dp[i - 1] + a);
        }
        cout << dp[n] << endl;
    }
    return 0;
}