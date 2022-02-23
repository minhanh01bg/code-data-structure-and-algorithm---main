#include <bits/stdc++.h>


#define ll        long long
#define pb              push_back
#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)
using namespace std;
// --------------------------------------------------------- //

vector<int> list_v[1005];
bool visited[1005];
int left_set[1005];
int v, e;

void resetState(int v, bool reInt) {
    FOR(i, 1, v + 1)  {
        if (!reInt) list_v[i].clear();
        visited[i] = false;
    }
    //left_set[1] = 1; // gia su dinh 1 o ben trai luon
}

bool check(int u) {
    int colorArr[v+1];
    FOR(i, 1, v+1) colorArr[i] = -1; // set all no color
    colorArr[u] = 1; // set 1st vertex
    queue<int> q;
    q.push(u);
    while (!q.empty())  {
        int vtx = q.front(); q.pop();
        for (auto i : list_v[vtx])  {
            if (colorArr[i] == -1)  {
                colorArr[i] = 1 - colorArr[vtx];
                q.push(i);
            }
            else if (colorArr[i] == colorArr[vtx]) {
                return false;
            }
        }
    }
    return true;
}

void getInput() {
    int a, b;
    cin >> v >> e;
    resetState(v, false);
    FOR(i, 0, e)  {
        cin >> a >> b;
        list_v[a].pb(b);
        list_v[b].pb(a);
    }
}

main (){
    faster();
    run() {
        getInput();
        FOR(i, 1, v + 1) 
            if (!check(i)) {
                cout << "NO" << endl;
                goto jump;
            }
            
        cout << "YES" << endl;
        jump:;
    }
    return EXIT_SUCCESS;
}