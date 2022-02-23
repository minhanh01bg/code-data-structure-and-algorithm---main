#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int oo = 1000111000;
typedef pair<int, int> ii;

vector<ii> a[100309];
int n, m;

int d[100309];

void dijkstra(int V) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[V] = 0;
    pq.push(ii(0, V));

    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int p, q, m, w,v;
        scanf("%d%d%d", &n, &m, &v);
        while (m--) {
            scanf("%d%d%d", &p, &q, &w);
            a[p].push_back(ii(w, q));
            a[q].push_back(ii(w, p));
        }
        dijkstra(v);
        for(int i=0;i<=n+1;i++)
            a[i].clear();
        for (int i = 1; i <= n; i++)
            printf("%d ", d[i]);
        printf("\n");
    }
}