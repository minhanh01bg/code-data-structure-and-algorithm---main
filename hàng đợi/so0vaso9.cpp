#include <bits/stdc++.h>
using namespace std;
int Stoi(string s)
{
    int d = 0;
    for (int i = 0; i < s.length(); i++)
    {
        d = (s[i] - '0') + d * 10;
    }
    return d;
}
vector<string> vec;
int k = 500;
void generatePrintBinary()
{
    queue<string> q;

    q.push("9");
    // q.push("7");
    while (k--)
    {
        string s1 = q.front();
        // q.pop();
        // string sk = q.front();
        q.pop();
        vec.push_back(s1);
        // vec.push_back(sk);
        string s2 = s1;
        string sk1 = sk;
        q.push(s1.append("0"));
        q.push(s2.append("9"));
        // q.push(sk.append("4"));
        // q.push(sk1.append("7"));
    }
}
int main()
{
    int t;
    cin >> t;
    generatePrintBinary();
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < vec.size(); i++)
            // if (Stoi(vec[i]) % n == 0)
            // {
                cout << vec[i] << " ";
                // break;
            // }
    }
    return 0;
}