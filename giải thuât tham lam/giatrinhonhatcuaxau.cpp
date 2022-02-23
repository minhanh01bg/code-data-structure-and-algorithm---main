#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define BEGIN() int t;cin>>t;while(t--)
#define FAST() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define endl "\n"
ll maxstring(string s,int k){
    int d[1000];
    memset(d,0,sizeof(d));
    FOR(i,0,s.size()-1)
        d[s[i]]++;
    priority_queue<ll, vector<ll>> pq;
    FOR(i,0,s.size()-1){
        if(d[s[i]]){
            pq.push(d[s[i]]);
            d[s[i]]=0;
        }
    }
    while(k>0&&!pq.empty()){
        k-=1;
        int t=pq.top()-1;
        pq.pop();
        pq.push(t);
    }
    int MAX=0;
    while(!pq.empty()){
        int t=pq.top();pq.pop();
        MAX+=t*t;
    }
    return MAX;
}
int main(){
    FAST()
    BEGIN(){
        int k;
        string s;
        cin >> k >> s;
        cout<<maxstring(s,k)<<endl;
    }
    return 0;
}