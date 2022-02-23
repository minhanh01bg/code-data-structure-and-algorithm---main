#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define run() int t;cin>>t;while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define reset(C) memset(C,0,sizeof(C))
#define endl "\n"
int main(){
    faster()
    run(){
        string str;
        cin >> str;
        int x=0,y=0;
        bool k[str.size()];
        memset(k,0,sizeof(k));
        FOR(i,0,str.size()-1){
            if(str[i]=='('){
                x++;
            }
            else {
                for(int j=i-1;j>=0;j--){
                    if(k[j]==false&&str[j]=='('){
                        y++;
                        k[j]=true;
                        break;
                    }
                }
            }
        }
        cout<<2*min(x,y)<<endl;
    }
}