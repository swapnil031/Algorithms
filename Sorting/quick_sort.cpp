#include<iostream>
using namespace std;
int partition(int a[],int lb,int ub){
    int pivot=a[ub];
    int partition_index=lb-1;
    for(int i=lb;i<ub;i++){
        if(a[i]<=pivot){
            partition_index++;
            swap(a[i],a[partition_index]);
        }
    }
    swap(a[partition_index+1],a[ub]);
    return partition_index+1;
}
void quicksort(int a[],int lb,int ub){
    if(lb>=ub)
        return;
    int k=partition(a,lb,ub);
    quicksort(a,lb,k-1);
    quicksort(a,k+1,ub);
    
}
void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int a[]={6,8,3,1,4,5,7};
    int n= sizeof(a)/sizeof(int);
    quicksort(a,0,n-1);
    print(a,n);
}