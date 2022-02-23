#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAX 20
 
int Stoi(string s){
    int d=0;
    for(int i=0;i<s.size();i++)
        d=d*10+(s[i]-'0');
    return d;
}
int main(){
    fast();
    run(){
        string str;
        cin >> str;
        stack<string> a;
        int d=0;
        FOR(i, 0, str.length()-1){
            if((str[i] >= '0' && str[i] <= '9'))
                a.push(string(1,str[i]));
            else {
                string s2=a.top();
                a.pop();
                string s=a.top();
                a.pop();
                d=0;
                if(str[i]=='/') d=Stoi(s)/Stoi(s2);
                if(str[i]=='*') d=Stoi(s)*Stoi(s2);
                if(str[i]=='-') d=Stoi(s)-Stoi(s2);
                if(str[i]=='+') d=Stoi(s)+Stoi(s2);
                string D=string(1,d+48);
                a.push(D);
            }
        }
        cout<<d<<endl;
    }
}