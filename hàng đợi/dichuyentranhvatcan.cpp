#include <bits/stdc++.h>
using namespace std;
int n, m, e, is, js, check, it, jt;
char s[1000][1000];
int c[1000][1000];
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

struct imf
{
    int x, y, h, lv;
};

bool check1(int i, int j)
{
    if (i < n && i >= 0 && j < m && j >= 0)
        return 1;
    return 0;
}

bool check2(int i, int j)
{
    if (s[i][j] == '.')
        return 1;
    return 0;
}

int kt()
{
    queue<imf> q;
    c[is][js] = 0;
    int tmpx, tmpy;
    for (int i = 0; i < 4; i++)
    {
        tmpx = is + x[i];
        tmpy = js + y[i];
        if (check1(is + x[i], js + y[i]) && check2(is + x[i], js + y[i]))
        {
            q.push({tmpx, tmpy, i, 1});
            c[tmpx][tmpy] = 1;
        }
    }

    while (!q.empty())
    {
        imf t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            tmpx = t.x + x[i];
            tmpy = t.y + y[i];
            int lv1 = (i == t.h) ? t.lv : t.lv + 1;
            if (check1(tmpx, tmpy) && check2(tmpx, tmpy) && (c[tmpx][tmpy] > lv1 || c[tmpx][tmpy] == 0))
            {
                c[tmpx][tmpy] = lv1;
                q.push({tmpx, tmpy, i, lv1});
            }
        }
    }
    return c[it][jt];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        m = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> s[i][j];
            }
        }
        cin >> is >> js >> it >> jt;
        for (int i = 0; i < n; i++)
            memset(c[i], 0, sizeof(c[i]));
        cout << kt() << endl;
    }
}