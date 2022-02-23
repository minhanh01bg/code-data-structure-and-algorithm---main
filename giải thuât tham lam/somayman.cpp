#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a=0,b=0;
        while(n>0){
            if(n%7==0){
                a++;
                n-=7;
            }
            else if(n%4==0){
                b++;
                n-=4;
            }
            else {
                a++;
                n-=7;
            }
        }
        if(n==0){
            for(int i=0;i<b;i++) cout<<4;
            for(int i=0;i<a;i++) cout<<7;
        }
        else cout<<-1;
        cout<<endl;
    }
}