#include<bits/stdc++.h>
#define run() int t;cin>>t;cin.ignore();while(t--)
#define ll long long
#define endl "\n"
#define FOR(i,l,r) for(int i=l;i<=r;i++)


using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    run(){  
        string s;
        getline(cin,s);
        stack<char>x;
        bool ok;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                ok=false;
                char k=x.top();x.pop();
                while(k!='('){
                    if(k=='+'||k=='-'||k=='*'||k=='/'){
                        ok=true;
                    }
                    k=x.top();
                    x.pop();
                }
                if(ok==false) break;
            }
            else x.push(s[i]);
        }
        if(ok==false) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
}