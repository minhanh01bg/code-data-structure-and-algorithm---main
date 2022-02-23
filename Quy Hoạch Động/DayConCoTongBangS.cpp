#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define reset(C) memset(C, 0, sizeof(C))
#define run()     \
	int N;        \
	cin >> N;     \
	cin.ignore(); \
	while (N--)
#define faster()                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
#define pause() system("pause");

// Namespaces

using namespace std;
/*--------------------------------------------------------------------------------*/

main()
{
	faster()
		run()
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		FOR(i, 0, n - 1)
		cin >> a[i];
		bool check[k + 1];
		reset(check);
		FOR(i, 0, n - 1)
			FORD(j, k, a[i])
				if (check[j - a[i]] == 1 || j == a[i])
					check[j] = 1;
		check[k] == 1 ? cout << "YES\n" : cout << "NO\n";
	}
	return EXIT_SUCCESS;
}