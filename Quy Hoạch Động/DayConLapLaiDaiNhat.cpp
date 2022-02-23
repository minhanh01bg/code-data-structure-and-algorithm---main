#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define ALL(C) c, c + n
int mod = 1e9 + 7;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define run()     \
	int N;        \
	cin >> N;     \
	cin.ignore(); \
	while (N--)
#define faster()                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
using namespace std;
// day con lap lai dai nhat
/*---------------------------------------------------------------------------------------------------------------------------------*/
signed main()
{
	faster();
	run()
	{
		int n;
		string str;
		cin >> n >> str;
		int dp[n + 1][n + 1];
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				if (i == 0 || j == 0)
					dp[i][j] = 0;
				else if (str[i - 1] == str[j - 1] && i - 1 != j - 1)
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << dp[n][n] << endl;
	}
	return EXIT_SUCCESS;
}