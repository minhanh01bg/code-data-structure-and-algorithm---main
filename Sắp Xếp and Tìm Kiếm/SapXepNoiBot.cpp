#include<bits/stdc++.h>
using namespace std;
int z=1;
void printArray(int a[], int n){
    cout<<"Buoc "<<z++<<": ";
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
    cout<<endl;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool haveSwap = false;
    for (i = 0; i < n-1; i++){
        haveSwap = false;
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                haveSwap = true; 
            }
        }
        if(haveSwap == false){
            break;
        }
        else printArray(arr,n);
    }
}
 
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    bubbleSort(a,n);
}