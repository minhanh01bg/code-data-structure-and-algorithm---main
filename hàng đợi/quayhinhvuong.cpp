#include <bits/stdc++.h>
#define reset(x) memset(x, 0, sizeof((x)))
#define VI vector<char>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define TR(it, a) for (typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define FAST                      \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
#define BEGIN \
	int t;    \
	cin >> t; \
	while (t--)
using namespace std;
string b, test;
void input()
{
	string a;
	b = "";
	FOR(i, 1, 6)
	{
		cin >> a;
		b += a;
	}
	test = "";
	FOR(i, 1, 6)
	{
		cin >> a;
		test += a;
	}
}
string a;
string left()
{
	b[0] = a[3];
	b[1] = a[0];
	b[2] = a[2];
	b[3] = a[4];
	b[4] = a[1];
	b[5] = a[5];
	return b;
}
string right()
{
	b[0] = a[0];
	b[1] = a[4];
	b[2] = a[1];
	b[3] = a[3];
	b[4] = a[5];
	b[5] = a[2];
	return b;
}
bool tester()
{
	if (b[0] == test[0] && b[1] == test[1] && b[2] == test[2] && b[3] == test[3] && b[4] == test[4] && b[5] == test[5])
		return true;
	return false;
}
int main()
{
	FAST
		queue<pair<string, int>>
			q;
	pair<string, int> u;
	BEGIN
	{
		input();
		q.push(make_pair(b, 0));
		while (1)
		{
			u = q.front();
			q.pop();
			b = u.first;
			a = u.first;
			if (tester())
			{
				cout << u.second << "\n";
				break;
			}
			else
			{
				q.push(make_pair(left(), u.second + 1));
				q.push(make_pair(right(), u.second + 1));
			}
		}
		while (q.size() > 0)
		{
			q.pop();
		}
	}
	return 0;
}