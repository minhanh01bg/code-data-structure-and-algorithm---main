#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int>stk;
    int t;t=100;
    while(t--){
        string s;
        getline(cin,s);
        int n=s.size();
        int d=0;
        
        for(int i=0;i<n;i++){
            if(s[i]<='9'&&s[i]>='0') d=int(s[i]-'0')+d*10;
        }
        int i=0;
        if(s[i]=='p'&&s[i+1]=='u'){
            stk.push_back(d);
        }
        else if(s[i]=='p'&&s[i+1]=='o'){
            stk.pop_back();
        }
        else if(s[i]=='s'){
            for(int i=0;i<stk.size();i++){
                cout<<stk[i]<<" ";
            }
            if(stk.empty()) cout<<"empty"; 
            cout<<endl;
        }
        
    }
}