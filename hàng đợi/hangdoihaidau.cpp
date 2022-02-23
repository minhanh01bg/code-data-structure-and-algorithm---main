#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define X first
#define Y second
#define run() int t;cin>>t;while(t--)
#define fast(); ios_base::sync_with_stdio(0); cin.tie(0);


int main(){
    fast();
    deque<int>x;
    string s;
    run()
    {
        cin>>s;
        if(s=="PUSHBACK"){
            int k;
            cin>>k;
            x.push_back(k);
        }
        else if(s=="PRINTFRONT"){
            
            if(x.empty()){ 
                cout<<"NONE"; 
             } else if(x.size()>0) cout<<x.front();
            cout<<endl;            
        }
        else if(s=="PUSHFRONT"){
            int z;
            cin>>z;
            x.push_front(z);
        }
        else if(s=="POPFRONT"&&!x.empty()){
            x.pop_front();
        }
        else if(s=="POPBACK"&&!x.empty()){
            x.pop_back();
        }
        else if(s=="PRINTBACK"){
            
            if(x.empty()){ 
                cout<<"NONE"; 
            }else if(x.size()>0) cout<<x.back();
            cout<<endl;
        }
    }
}