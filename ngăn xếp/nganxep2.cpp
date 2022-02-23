#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<int>stk;
    int t;cin>>t;
    string s;
    cin.ignore();
    while(t--){
        
        getline(cin,s);
        int n=s.size();
        int d=0;
        
        for(int i=0;i<n;i++){
            if(s[i]<='9'&&s[i]>='0') d=int(s[i]-'0')+d*10;
        }
        int i=0;
        if(s[i]=='P'&&s[i+1]=='U'){
            stk.push(d);
        }
        else if(s[i]=='P'&&s[i+1]=='O'){
            if(!stk.empty())
                stk.pop();
        }
        else if(s[i]=='P'&&s[i+1]=='R'){
            if(!stk.empty())
                cout<<stk.top();
            else cout<<"NONE"; 
            cout<<endl;
        }
    }
}