#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define run()     \
	int N;        \
	cin >> N;     \
	cin.ignore(); \
	while (N--)



#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOR2(i, a, b) for (ll i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define FORA(x, C) for (auto x : C)
#define WHILE(x, y) while (cin >> x >> y)
#define WHILEF(x, y, f) while (f >> x >> y)
#define WHILE2(x) while (cin >> x)
#define WHILEGL(a) while (getline(cin, a))
#define WHILEGLF(a, f) while (getline(f, a))

#define faster()                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
#define pause() system("pause");

using namespace std;

void test()
{
	int n;
	cin >> n;
	int a[n];
	FOR(i, 0, n - 1)
		cin >> a[i];
	int s[n];
	stack<int> st;
	s[0] = 1;
	st.push(0);
	FOR(i, 1, n - 1)
	{
		while (!st.empty() && a[st.top()] <= a[i])
			st.pop();
		s[i] = (st.empty()) ? (i + 1) : (i - st.top());
		st.push(i);
	}
	FOR(i, 0, n - 1)
		cout << s[i] << " ";
	cout << endl;
}

main()
{
	faster()
		run()
			test();

	return 0;
}