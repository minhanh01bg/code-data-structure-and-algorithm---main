#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define f first
#define s second
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define run() int test; cin>>test; cin.ignore(); while(test--)

#define FOR(i,a,b)                    	for (int i=a; i<=b; i++)
#define FOR2(i,a,b)                   	for (ll i=a; i<=b; ++i)
#define FORD(i,a,b) 					for (int i=a; i>=b; i--)
#define FORA(x,C) 						for (auto x:C)

#define reset(C) 						memset(C,0,sizeof(C))
#define clearQueue(C, x) 				C = queue<x> ()
#define Fill(C,a) 						fill(C.begin(), C.end(), a)


#define SORTC(C,check) 					sort(C.begin(), C.end(), check)

#define um(x,y) 				unordered_map<x,y> 
#define m(x,y) 					map<x,y> 
#define p(x,y) 					pair<x,y> 
#define us(x) 					unordered_set<x> 
#define vec(x) 					vector<x> 
#define vec2(C,x,y,token) 		vector<vector<token> > C(x, vector<token> (y, 0))
#define pq(x) 					priority_queue<x>
#define reverse_pq(x) 			priority_queue<x, vector<x>, greater<x> >

	// System

#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pause() system("pause");
using namespace std;

int number(string str){
    int d=0;
    FOR(i,0,str.size()-1){
        if(str[i]=='^'){
            d=i+1;
        }
    }
    int k=0;
    FOR(i,d,str.size()-1){
        k=k*10+(str[i]-'0');
    }
    return k;
}

int heso(string str){
    int d=0;
    FOR(i,0,str.size()-1){
        if(str[i]=='*'){
            d=i-1;
        }
    }
    int k=0;
    FOR(i,0,d){
        k=k*10+(str[i]-'0');
    }
    return k;
}

string chuyen(int d,string str){
    string s="";
    while(d){
        int n=d%10;
        s=char(n+'0')+s;
        d/=10;
    }
    FOR(i,0,str.size()-1){
        if(str[i]=='*'){
            d=i;
        }
    }
    FOR(i,d,str.size()-1){
        s+=str[i];
    }
    return s;
}
int main() {
    faster();
    run() {
        string str;
        getline(cin,str);
        stack<string> st;
        string s="";
        FOR(i,0,str.size()-1){
            if(str[i]!=' ' && str[i]!= '+')
                s+=str[i];
            if(str[i]==' ' && s!="") {
                st.push(s);
                s="";
            }
        }
        st.push(s);
        string str1;
        getline(cin,str1);
        stack<string> st2;
        s="";
        FOR(i,0,str1.size()-1){
            if(str1[i]!=' ' && str1[i]!= '+')
                s+=str1[i];
            if(str1[i]==' ' && s!="") {
                st2.push(s);
                s="";
            }
        }
        st2.push(s);

        stack<string> save;
        while(st2.size()!=0){
            string s1=st.top(), s2=st2.top();
            if(number(s1)>number(s2)){
                save.push(s2);
                st2.pop();
            }
            else if(number(s1)==number(s2)){
                int d=heso(s1) + heso(s2);
                save.push(chuyen(d,s1));
                st.pop(); st2.pop();
            }
            else {
                save.push(s1);
                st.pop();
            }
        }
        while(!st.empty()){
            save.push(st.top());
            st.pop();
        }
        while(save.size()){
            if(save.size()!=1)
                cout<<save.top()<<" "<<"+"<<" ";
            else cout<<save.top();
            save.pop();
        }
        cout<<endl;
    }
}