#include<iostream>
using namespace std;

//heapify finction
void heapify(int *a,int n,int i){
	int max=i;
	int left=2*i+1;
	int right=2*i+2;
	if (left<n && a[left]>a[max])
	{
		max=left;
	}
	if (right<n && a[right]>a[max])
	{
		max=right;
	}
	if(max!=i){
	swap(a[i],a[max]);
	heapify(a,n,max);
	}
}

//creating the maxheap
void maxheap(int *a,int n){
	for(int i=(n/2)-1;i>=0;i--){
		heapify(a,n,i);
	}
}

//deleting the max element
int extract_max(int a[],int *n){
	if(*n<=0){
		return 0;
	}
	int t=*n;
	int max=a[0];
	a[0]=a[t-1];
	*n=*n-1;
	maxheap(a,*n);
	return max;
}

//changing the value of a existing key with a larger value
void increase_key(int *a,int i,int key){
	if(key<a[i]){
		cout<<"error";
	}
	a[i]=key;
	while(i>0 && a[i]>a[(i-1)/2]){
		swap(a[i],a[(i-1)/2]);
		i=(i-1)/2;
	}
}


//inserting an element in an existing max heap
void insert_key(int a[],int *n,int key){
	if(*n==0){
		cout<<"error";
	}
	*n=*n+1;
	int t=*n;
	t=t-1;
	a[t]=key;
	while(t>0 && a[t]>a[(t-1)/2]){
		swap(a[t],a[(t-1)/2]);
		t=(t-1)/2;
	}
}

void printarray(int *a,int n){
	cout<<"the array is " ;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int a[]={2,8,4,5,9,7};
	int n=sizeof(a)/sizeof(int);
	printarray(a,n);
	maxheap(a,n);
	printarray(a,n);
	cout<<"the maximum element is "<<extract_max(a,&n)<<endl;
	printarray(a,n);
	increase_key(a,3,10);
	printarray(a,n);
	insert_key(a,&n,100);
	printarray(a,n);
}