#include<bits/stdc++.h>
    #define ll long long
// test

    #define BEGIN() int t;cin>>t;while(t--)
    #define FAST() ios_base::sync_with_stdio(0);cin.tie(0);
	
// acronym
    #define pob pop_back
    #define EL printf("\n")
    #define pb push_back
    #define FOR(i,l,r) for (int i=l;i<=r;i++)
    #define FORD(i,r,l) for (int i=r;i>=l;i--)
    
    using namespace std;

int V;

pair<double, double> coordinate[101];
double graph[101][101];

double distance(int u, int v) {
    return sqrt(pow((coordinate[u].first - coordinate[v].first), 2) + pow((coordinate[u].second - coordinate[v].second), 2));
}

void PRIM(void){
    int k, top, l, t, u;
    int s[100];
    double min, w;
    int sc = 0; w = 0; u = 1;
    top = 1;
    s[top] = u;
    bool chuaxet[100];
    FOR(i,1,100)
        chuaxet[i]=true;
    chuaxet[u]=false;
    while (sc < V - 1) {
        min = INT_MAX;
        for (int i = 1; i <= top; i++){
            t = s[i];
            for (int j = 1; j <= V; j++){
                if (chuaxet[j] && min >graph[t][j]){
                    min = graph[t][j];
                    k = t;
                    l = j;
                }
            }
        }
        sc++;
        w = w + min;
        chuaxet[l] = false; 
        top++;
        s[top] = l;
    }
    cout << fixed << setprecision(6) << w << endl;
}
void solve() {
    cin >> V;
    double x, y;
    FOR(i,1,100)
        FOR(j,1,100)
            graph[i][j]=INT_MAX;
    FOR(i,1,100){
        coordinate[i].first=0;
        coordinate[i].second=0;
    }
    FOR(i, 1, V) {
        cin >> x >> y;
        coordinate[i].first = x, coordinate[i].second = y;
    }
    FOR(u, 1, V)
        FOR(v, 1, V)
            graph[u][v] = distance(u, v);

    PRIM();
}

int main() {
    FAST()
    BEGIN()
        solve();
    return 0;
}