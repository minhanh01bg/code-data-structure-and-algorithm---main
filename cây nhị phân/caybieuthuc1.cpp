/*
input
2

ab+ef*g*-
wlrb+-*
output
a + b - e * f * g

w * l - r + b
*/
#include<bits/stdc++.h>
using namespace std;
#define Nothing					"mikey"
#define run() int t;cin>>t;while(t--)
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long
main() {
    faster()
    run(){
        string str;
        cin>>str;
        stack<string>str1;
        FOR(i,0,str.length()-1){
            if((str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z'))
                str1.push(string(1,str[i]));
            else{
                string a=str1.top();
                str1.pop();
                string b=str1.top();
                str1.pop();
                str1.push(b+str[i]+a);
            }
        }
        cout<<str1.top()<<"\n";
    }
    return EXIT_SUCCESS;
}