#include<iostream>
using namespace std;
 void sort(int a[],int n){
    int i,j;
    for(i=1;i<n;i++){
        int temp=a[i];
        for(j=i-1;j>=0 && a[j]>temp;j--){
            a[j]=a[j+1];
        }
        a[j+1]=temp; //todo  (as while exiting the loop the j is decremented by 1)
    }
}
void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int arr[]={1,6,4,3,5};
    int n=sizeof(arr)/sizeof(int);
    sort(arr,n);
    print(arr,n);
}