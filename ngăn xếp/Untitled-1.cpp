#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string str;
    cin>>t;cin.ignore();
    while(t--){
        getline(cin,str);
        stack<int> st;
        int d=1;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                st.push(d);
                cout<<d<<" ";
                d++;
                
            }
            if(str[i]==')'){
                cout<<st.top()<<" ";
                st.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}