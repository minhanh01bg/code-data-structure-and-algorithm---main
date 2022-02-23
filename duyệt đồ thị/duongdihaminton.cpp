#include <bits/stdc++.h>
#define pb              push_back
#define rs(A,x)         memset(A, x, sizeof(A))
#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

#define V 1001
using namespace std;

vector<int> list_v[V];
bool visited[V], hasHalPath;
int X[V];
int v, e, u, u1;

void Hal(int k) {
    for (auto y : list_v[X[k-1]])  {
        if (hasHalPath) return;
        if (k == v+1)  {
            hasHalPath = true;
            return;
        }
        else if (visited[y] == false)  {
            X[k] = y;
            visited[y] = true;
            Hal(k+1);
            visited[y] = false;
        }
    }
}

bool Hamilton(int u) {
    visited[u] = true;
    X[1] = u;
    Hal(2);
    return hasHalPath;
}

main() {
    faster()
    run() {
        rs(visited, false);
        hasHalPath = false;
        int a, b, flag = 0; 
        cin >> v >> e;
        FOR(i, 1, v + 1) list_v[i].clear();
        FOR(i, 0, e) {
            cin >> a >> b;
            list_v[a].pb(b);
            list_v[b].pb(a);
        }
        FOR(i, 1, v + 1) {
            if (Hamilton(i))  {
                cout << 1<<endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << 0<<endl;
    }
    return EXIT_SUCCESS;
}