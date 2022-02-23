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

int main()
{
    FAST
        BEGIN
    {
        string s;
        cin >> s;
        stack<int> mo;
        FOR(i, 0, s.size())
        {
            if (s[i] == '(')
                mo.push(i);
            else if (s[i] == ')')
            {
                // if(!mo.empty()){
                int top = mo.top();
                mo.pop();
                if (top > 0 && s[top - 1] == '-')
                {
                    REP(j, top, i)
                    {
                        if (s[j] == '+')
                            s[j] = '-';
                        else if (s[j] == '-')
                            s[j] = '+';
                    }
                }
                // }
            }
        }
        FOR(i, 0, s.size())
        {
            if (s[i] != '(' && s[i] != ')')
                cout << s[i];
        }
        cout << endl;
    }
    return 0;
}