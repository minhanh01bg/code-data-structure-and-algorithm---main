#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define endl "\n"
/**/

int dynamic(int *a, int *b, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j < b[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - b[i]] + a[i]);
        }
    }
    return dp[n][m];
}
int main()
{
    run()
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[n];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        cout << dynamic(a, b, n, m) << endl;
    }
    return 0;
}
/*
int count(ll n){//SỐ BDN 1
    int Count=0;
    queue<ll>b;
    b.push(1);
    ll t;
    while(!b.empty()){
        t=b.front();
        b.pop();
        if(t<=n) {Count++;

            b.push(t*10);
            b.push(t*10+1);
        }
        if(t>n) break;
        
    }
    return Count;
}
int main(){
    run(){
        ll n;
        cin>>n;
        cout<<count(n)<<endl;
    }
}*/