#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x=0,binary[1000],k=i;
            while(k>0){
                binary[x]=k%2;
                k/=2;
                x++;
            }
            for(int j=x-1;j>=0;j--) cout<<binary[j];
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}