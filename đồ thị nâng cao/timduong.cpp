#include <bits/stdc++.h>
using namespace std;

#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

// --------------------------------------------------------- //


int n, m, x3, x2, y3, y2, arr[501][501]; 
bool flag;
void move(int x, int y, string c, int cnt)
{
    int l = c.size();
    if (flag) return;
    if (l > 1 && c[l - 1] != c[l - 2]) cnt++;
    if (cnt > 2) return;

    if (x == x2 && y == y2)
    {
        flag = true;
        return;
    }
    else 
    {
        if (arr[x + 1][y] == 1 && x + 1 < n)
        {
            arr[x][y] = 0;
            move(x + 1, y, c + "D", cnt);
            arr[x][y] = 1;
        }
        if (arr[x][y - 1] == 1 && y - 1 >= 0)
        {
            arr[x][y] = 0;
            move(x, y - 1, c + "L", cnt);
            arr[x][y] = 1;
        }
        if (arr[x][y + 1] == 1 && y + 1 < n)
        {
            arr[x][y] = 0;
            move(x, y + 1, c + "R", cnt);
            arr[x][y] = 1;
        }
        if (arr[x - 1][y] == 1 && x - 1 >= 0)
        {
            arr[x][y] = 0;
            move(x - 1, y, c + "U", cnt);
            arr[x][y] = 1;
        }
    }    
}
void reset();
void getip();


void solve()
{
    move(x3,y3,"",0);
    if (flag)
    {
        cout << "YES" << endl;
    }
    else 
    {
        cout << "NO"  << endl;
    }
}

int main ()
{
    faster();
    run()
    {
        cin >> n >> m;
        reset();
        getip();
        solve();
    }
    return 0;
}


// --------------------------------------------------------- //
void getip()
{   char x;
    FOR(i, 0, n)
        FOR(j, 0, m)
        {
            cin >> x;
            if (x == '*')
                arr[i][j] = 0;
            else if (x == 'S')
            {
                x3 = i;
                y3 = j;
                arr[i][j] = 1;
            }
            else if (x == 'T')
            {
                x2 = i;
                y2 = j;
                arr[i][j] = 1;
            }
            else
                arr[i][j] = 1;
        }
}

void reset()
{
    flag = false;
}