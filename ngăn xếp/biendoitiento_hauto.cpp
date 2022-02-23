#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAX 20
 
int main(){
    fast();
    run(){
        string str;
        cin >> str;
        stack<string> a;
        FORD(i,str.length()-1,0){
            if((str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z'))
                a.push(string(1,str[i]));
            else {
                string s=a.top();
                a.pop();
                string s2=a.top();
                a.pop();
                a.push(s+s2+str[i]);
            }
        }
        cout<<a.top()<<endl;
    }
}