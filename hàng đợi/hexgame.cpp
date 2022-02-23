#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        stack<ll> values;
        stack<char> mo;    
        int i;
        for(i=0;i<s.length();i++)
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