#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EL printf("\n")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a) memset(a, 0, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define run() int t;cin>>t;while(t--)
#define endl "\n"
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define reset(x) memset(x,0,sizeof((x)))
vector<int> calcu;
int a[5],b[6];
bool ok[6];
int number[6];
void init(){
    FOR(i,1,5)
        ok[i] = true;
    FOR(i,1,5) 
        cin >> number[i];
}

void res(){
    FOR(i,1,4) calcu.pb(a[i]);
    // FOR(i,1,4) cout<<a[i];
    // cout<<" ";
}

void Try(int i){
    FOR(j,1,3){
        a[i]=j;
        if(i==4) res();
        else Try(i+1);
    }
}

bool res1(){
    int s=0;
    for(int i=0;i<calcu.size();){
        s=0;
        if(calcu[i]==1)
            s=number[b[1]]+number[b[2]];
        if(calcu[i]==2)
            s=number[b[1]]-number[b[2]];
        if(calcu[i]==3)
            s=number[b[1]]*number[b[2]];

        if(calcu[i+1]==1)
            s+=number[b[3]];
        else if(calcu[i+1]==2)
            s-=number[b[3]];
        else if(calcu[i+1]==3)
            s*=number[b[3]];

        if(calcu[i+2]==1)
            s+=number[b[4]];
        else if(calcu[i+2]==2)
            s-=number[b[4]];
        else if(calcu[i+2]==3)
            s*=number[b[4]];

        if(calcu[i+3]==1)
            s+=number[b[5]];
        else if(calcu[i+3]==2)
            s-=number[b[5]];
        else if(calcu[i+3]==3)
            s*=number[b[5]];
        if(s==23){
            return true;
        }
        i+=4;
    }
    return false;
}

bool x=false;
void Try1(int i){
    FOR(j,1,5){
        if(ok[j]){
            b[i]=j;ok[j]=false;
            if(i==5) {
                if(res1())  
                    x=true;
            }
            else Try1(i+1);
            ok[j]=true;
        }
    }
}

int main(){
    fast()
    Try(1);
    run(){
        x=false;
        init();
        Try1(1);
        if(x==true)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}