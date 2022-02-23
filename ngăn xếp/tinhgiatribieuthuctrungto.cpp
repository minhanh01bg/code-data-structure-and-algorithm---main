#include <bits/stdc++.h>
#define ll        long long
#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

using namespace std;
bool So(char c){
    if(c>='0' && c<='9')
    {
        return true;
    }
    else return false;
}
bool Toantu(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    {
        return true;
    }
    else return false;
}
ll res(ll a, ll b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
int Uutien(char c){
    if(c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1; 
}
int main() {
    faster()
    run(){
        string s;
        cin>>s;
        stack<ll> values;
        stack<char> mo;    
        int i;
        FOR(i,0,s.length())
        {
            if(So(s[i]))
            {
                ll val=0;
                while(i<s.length() && So(s[i]))
                {
                    val=val*10+(s[i]-'0');
                    i++;
                    
                }
                values.push(val);
                i--;    
            }
            else if(s[i]=='(')
            {
                mo.push(s[i]);    
            }
            else if(s[i]==')')
            {
                while((mo.top()!='(') && (!mo.empty()))
                {
                    ll val2 = values.top();
                    values.pop();
                    
                    ll val1 = values.top();
                    values.pop();
                    
                    char op = mo.top();
                    mo.pop();
                    values.push(res(val1,val2,op));
    }
                if(mo.top()=='(')
                {
                    mo.pop();
                }
            }
            else
            {
                while(!mo.empty()&&Uutien(s[i])<=Uutien(mo.top()))
                {
                    ll val2 = values.top();
                    values.pop();

                    ll val1 = values.top();
                    values.pop();

                    char op = mo.top();
                    mo.pop();

                    values.push(res(val1, val2, op));
                }
                mo.push(s[i]);
            }        
        }        
        while(!mo.empty()){
            ll val2 = values.top();
            values.pop();
            ll val1 = values.top();
               values.pop();
               char op = mo.top();
               mo.pop();
            values.push(res(val1, val2, op));
        }
        cout<<values.top();
        cout<<endl;
    }
    return 0;
}