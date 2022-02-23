#include <bits/stdc++.h>
using namespace std;
#define er              erase
#define pb              push_back
#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)
#define rs(A,x)         memset(A, x, sizeof(A))
// --------------------------------------------------------- //


struct edge {
    int val, v1, v2;
    bool operator<(const edge& b) const {
        if (val == b.val){
            if (v1 == b.v1)
                return v2 > b.v2;
            return v1 > b.v1;
        }
        return val > b.val;
    }
};

struct ele {
    int ver1, ver2;
};

vector <vector<int>> adja;
vector <edge> s;
bool use[101]; int n, a[101][101];

void reset() {
    adja.resize(n + 1);
    FOR(i, 0, n + 1) adja[i].clear();
    s.clear();
    rs(a, 0); 
    rs(use, false);
}

// --------------------Try using Prim----------------------- //
void prim(int node) {
    int d = 0, num = 1; edge temp;
    use[node] = true;
    
    priority_queue <edge> q;
    for (int i = 0; i < adja[node].size(); i++)
        q.push(s[a[node][adja[node][i]]]);
    
    while (num < n) {
        temp = q.top();
        if (use[temp.v1]) {
            if (use[temp.v2]) {
                q.pop();
                continue;
            }
            else {
                use[temp.v2] = true;
                for (int i = 0; i < adja[temp.v2].size(); i++)
                    q.push(s[a[temp.v2][adja[temp.v2][i]]]);
            }
        }

        else {
            use[temp.v1] = true;
            for (int i = 0; i < adja[temp.v2].size(); i++)
                q.push(s[a[temp.v1][adja[temp.v1][i]]]);
        }

        d += temp.val;
        num++;
    }

    cout << d << endl;
}

int main() {
    faster();
    run() {
        int cnt = 0, m, x, y, z; edge temp;
        cin >> n >> m;
        reset();

        FOR(i, 0, m) {
            cin >> x >> y >> z;

            a[x][y] = cnt;
            cnt++;
            temp.val = z;
            temp.v1  = x;
            temp.v2  = y;
            s.push_back(temp);
            adja[x].push_back(y);

            a[y][x] = cnt;
            cnt++;
            temp.val = z;
            temp.v1  = y;
            temp.v2  = x;
            s.push_back(temp);
            adja[y].push_back(x);
        }
        prim(1);
    }
}