#include <bits/stdc++.h>
using namespace std;
int B[1001][1001];
bool ok[1001];
int u, n;
void DFS(int i)
{
    stack<int> x;
    cout << i << " ";
    ok[i] = true;
    x.push(i);
    while (!x.empty())
    {
        int s = x.top();
        x.pop();
        for (int j = 1; j <= u; j++)
        {
            if (B[s][j] == 1 && ok[j] == false)
            {
                cout << j << " ";
                ok[j] = true;
                x.push(s);
                x.push(j);
                break;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int v;
        cin >> u >> v >> n;
        int U, V;
        for (int i = 1; i <= u; i++)
            ok[i] = false;

        for (int i = 1; i <= u; i++)
            for (int j = 1; j <= u; j++)
                B[i][j] = 0;

        for (int i = 1; i <= v; i++)
        {
            cin >> U >> V;
            B[U][V] = 1;
            B[V][U] = 1;
        }
        DFS(n);
        cout << endl;
    }
}