#include <bits/stdc++.h>

#define ll        long long
#define endl      <<endl
#define pii       pair<int, int>
#define MIN       INT_MIN
#define MAX       LLONG_MAX
#define m         %u

#define res(x)          resize(x)
#define sz()            size()
#define er              erase
#define pb              push_back
#define eleV            vector <ele>
#define all(vec)        vec.begin(), vec.end()
#define rs(A,x)         memset(A, x, sizeof(A))
#define Unique(C)       C.erase(unique(C.begin(), C.end()), C.end())
#define pq(x)           priority_queue<x>
#define neg_pq(x)       priority_queue<x, vector<x>, greater<x>>
#define vec2(C,x,y,tp)  vector<vector<tp> > C(x, vector<tp> (y, 0))

#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

using namespace std;

void solve() {
    int n, x, y; 
    char z;
    vector<int> s;
    cin >> n;

    FOR(i, 0, n) {
        cin >> x >> y >> z;
        s.pb(x);
        s.pb(y);
    }
    sort(all(s));
    Unique(s);
    FOR(i, 0, s.sz()) cout << s[i] << " ";
    cout endl;
}

main () {
    faster()
    run(){
        solve();
    }
    return EXIT_SUCCESS;
}
