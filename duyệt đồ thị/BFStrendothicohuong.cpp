#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ii pair<ll, ll>
#define all(C) C.begin(), C.end()
#define run()     \
    int N;        \
    cin >> N;     \
    cin.ignore(); \
    while (N--)

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOR2(i, a, b) for (ll i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define FORD2(i, a, b) for (ll i = a; i >= b; i--)
#define FORA(x, C) for (auto x : C)
#define REP(i, a) for (int i = 0; i <= a; i++)
#define REP2(i, a) for (ll i = 0; i <= a; i++)
#define REPD(i, a) for (int i = a; i >= 0; i--)
#define FORx(i, m, n, x) for (int i = m; i <= n; i += x)

#define Sort(C) sort(C, C + n)
#define SORT(C) sort(c.begin(), C.end())

#define reset(C) memset(C, 0, sizeof(C))
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define pause() system("pause");

using namespace std;
int V, E;
int a[1001][1001];
bool check[1001];
void BFS(int u)
{
    for (int i = 1; i <= V; i++)
        check[i] = false;
    queue<int> Q;
    Q.push(u);
    cout << u << " ";
    check[u] = 1;
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        FOR(i, 1, V)
        {
            if (a[v][i] == 1 && !check[i])
            {
                check[i] = 1;
                Q.push(i);
                cout << i << " ";
            }
        }
    }
    cout << endl;
}

main()
{
    faster()
        run()
    {
        cin >> V >> E;
        int start;
        cin >> start;
        int v, u;
        FOR(i, 1, V)
        {
            FOR(j, 1, V)
            a[i][j] = 0;
        }
        FOR(i, 0, E - 1)
        {
            cin >> v >> u;
            a[v][u] = 1;
            a[u][v] = 1;
        }
        BFS(start);
    }
    return EXIT_SUCCESS;
}