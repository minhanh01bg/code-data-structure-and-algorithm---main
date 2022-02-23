/* code by vu minh anh */
#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
// int shortestChainLen( string start, string target,set<string>& D) {
//     if(start == target)
//       return 0;
//     if (D.find(target) == D.end())
//         return 0;
//     int level = 0, wordlength = start.size();
//     queue<string> Q;

//     Q.push(start);

//     while (!Q.empty()) {
//         ++level;
//         int sizeofQ = Q.size();
//         for (int i = 0; i < sizeofQ; ++i) {
//             string word = Q.front();
//             Q.pop();
//             for (int pos = 0; pos < wordlength; ++pos) {
//                 char orig_char = word[pos];
//                 for (char c = 'A'; c <= 'Z'; ++c) {
//                     word[pos] = c;
//                     if (word == target)
//                         return level + 1;
//                     if (D.find(word) == D.end())
//                         continue;
//                     D.erase(word);
//                     Q.push(word);
//                 }
//                 word[pos] = orig_char;
//             }
//         }
//     }
//     return 0;
// }
int shortestChainLen(string start, string target, set<string> &D)
{

    if (start == target)
        return 0;
    map<string, vector<string>> umap;

    for (int i = 0; i < start.size(); i++)
    {
        string str = start.substr(0, i) + "*" + start.substr(i + 1);
        umap[str].push_back(start);
    }
    for (auto it = D.begin(); it != D.end(); it++)
    {
        string word = *it;
        for (int j = 0; j < word.size(); j++)
        {
            string str = word.substr(0, j) + "*" + word.substr(j + 1);
            umap[str].push_back(word);
        }
    }
    queue<pair<string, int>> q;

    map<string, int> visited;

    q.push(make_pair(start, 1));
    visited[start] = 1;
    while (!q.empty())
    {
        pair<string, int> p = q.front();
        q.pop();

        string word = p.first;
        int dist = p.second;
        if (word == target)
        {
            return dist;
        }
        for (int i = 0; i < word.size(); i++)
        {
            string str = word.substr(0, i) + "*" + word.substr(i + 1);

            vector<string> vect = umap[str];
            for (int j = 0; j < vect.size(); j++)
            {
                if (visited[vect[j]] == 0)
                {
                    visited[vect[j]] = 1;
                    q.push(make_pair(vect[j], dist + 1));
                }
            }
        }
    }
    return 0;
}
int main()
{
    fast();
    run()
    {
        string a, b;
        int M;
        cin >> M >> a >> b;
        string str;
        set<string> D;
        int count = 0;
        FOR(i, 0, M - 1)
        {
            cin >> str;
            D.insert(str);
        }
        cout << shortestChainLen(a, b, D) << endl;
    }
}