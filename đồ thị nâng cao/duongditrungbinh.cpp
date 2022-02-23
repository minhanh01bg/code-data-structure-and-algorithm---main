#include <bits/stdc++.h>
using namespace std;
int n,m;
int C[105][105], connected[105];

void FLOYD(){
    for(int k=1;k<=n;k++)
        for(int u=1;u<=n;u++)
            for(int v=1;v<=n;v++)
                if (C[u][v] > C[u][k]+C[k][v])
                    C[u][v] = C[u][k]+C[k][v];
}

main(){
    int t,u,v,i,j;
    cin >> t;
    while(t--){
        memset(connected, 0, sizeof(connected));
        cin >> n >> m;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j) C[i][j] = 0;
                else C[i][j] = 1e9;

        for(i=1;i<=m;i++){
            cin >> u >> v;
            // connected[u] = connected[v] = 1;
            C[u][v] = 1;
        }

        FLOYD();

        int ans = 0, num = 0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i != j  && C[i][j] < 1e9){ //&& connected[i] && connected[j]
                    ans += C[i][j];
                    num++;
                }

        cout << fixed << setprecision(2);
        cout << (double)ans / num << endl;
    }
}