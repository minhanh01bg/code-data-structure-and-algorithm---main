#include <bits/stdc++.h>
#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

using namespace std;
// --------------------------------------------------------- //

string n1, n2, n3, op;

int gc(char x, int num) {
    if (x == '?')
        return num;
    return x - '0';
}

char gop(char x, int num) {
    if (x == '?') {
        if (num)
            return '+';
        return '-';
    }
    return x;
}

void solve() {
    if (op[0] == '/' || op[0] == '*') {
        cout << "WRONG PROBLEM!" << endl;
        return;
    }
    FOR(i, 1, 10) {
        int s1 = gc(n1[0], i);
        FOR(j, 0, 10) {
            int s2 = s1 * 10 + gc(n1[1], j); 
            FOR(m, 1, 10) {
                int a1 = gc(n2[0], m);
                FOR(n, 0, 10) {
                    int a2 = a1 * 10 + gc(n2[1], n);
                    FOR(x, 1, 10) {
                        int b1 = gc(n3[0], x);
                        FOR(y, 0, 10) {
                            int b2 = b1 * 10 + gc(n3[1], y);
                            FOR(k, 0, 2) {
                                char oprt = gop(op[0], k);
                                if (oprt == '+') {
                                    if (s2 + a2 == b2) {
                                        cout << s2 << " + " << a2 << " = " << b2 << endl;
                                        return;
                                    }
                                }
                                else {
                                    if (s2 - a2 == b2) {
                                        cout << s2 << " - " << a2 << " = " << b2 << endl;
                                        return;
                                    }
                                }
                            }
                            b2 -= b2;
                        }
                    }
                    a2 -= a2;
                }
            }
            s2 -= s2;
        }
    }
    cout << "WRONG PROBLEM!" << endl;
}

main () {
    faster();
    run() {
        cin >> n1 >> op >> n2 >> n3 >> n3;
        solve();
    }
    return 0;
}