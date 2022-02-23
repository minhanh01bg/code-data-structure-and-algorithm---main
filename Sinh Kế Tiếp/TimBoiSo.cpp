#include<bits/stdc++.h>
using namespace std;

long long mod(string s,int n){
    long long d=0;
    for(int i=0;i<s.length();i++){
        d=(s[i]-'0')+d*10;
        d=d%n;
    }
    return d;
}
string getMinimumMultipleOfBinaryDigit(int N) {
    queue<string> q;
    set<int> visit;
 
    string t = "9";
 
    q.push(t);
    while (!q.empty()){
        t = q.front();      q.pop();
 
        int rem = mod(t, N);
 
        if (rem == 0)
            return t;
        else if(visit.find(rem) == visit.end())
        {
            visit.insert(rem);
            q.push(t + "0");
            q.push(t + "9");
        }
    }
    return "";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        cout<<getMinimumMultipleOfBinaryDigit(n)<<endl;
    }
}