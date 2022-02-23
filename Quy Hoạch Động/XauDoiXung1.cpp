#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define FAST                      \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
#define BEGIN \
	int t;    \
	cin >> t; \
	while (t--)
using namespace std;

/*--------------------------------------------*/

// tim chuoi con chung dai nhat,
// kq = độ dài chuỗi - độ dài chuỗi con chung
int main()
{
	FAST
		BEGIN
	{
		string a;
		cin >> a;
		string b = a;
		reverse(b.begin(), b.end()); // dao nguoc
		int n = a.length();
		int c[n + 1][n + 1];
		REP(i, 0, n)
		{
			REP(j, 0, n)
			{
				if (i == 0 || j == 0)
					c[i][j] = 0;
				else if (a[i - 1] == b[j - 1])
					c[i][j] = c[i - 1][j - 1] + 1;
				else
					c[i][j] = max(c[i][j - 1], c[i - 1][j]);
			}
		}
		cout << n - c[n][n] << "\n";
	}
	return 0;
}