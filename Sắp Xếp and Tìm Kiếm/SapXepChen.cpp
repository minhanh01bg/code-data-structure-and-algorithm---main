#include<bits/stdc++.h>
using namespace std;
int z=0;
void printArray(int a[], int n){
    cout<<"Buoc "<<z++<<": ";
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
    cout<<endl;
}
void insertionSort(int a[], int n){
	int index, value;
	for (int i = 1; i < n; i++){
		index = i;
		value = a[i];
        printArray(a,index);
		while (index > 0 && a[index - 1] > value){
			a[index] = a[index - 1];
			index --;
		}
		a[index] = value;
	}
    printArray(a,n);
} 
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    insertionSort(a,n);
}