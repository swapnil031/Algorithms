#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(float *a,int n){
	//cout<<"the array is ";
	for(int i=0;i<n;i++){
	cout<<a[i]<<" ";
	}
	cout<<endl;
}

void knapsack(int n,int capacity,float *profit,float *weight,float *ratio){
	float tp=0;
	float x[20];
	int i;
	for(int j=0;j<n;j++){
		x[j]=0.0;
	}
	for(i=0;i<n;i++){
		if(capacity>0 && weight[i]<capacity){
			x[i]=1.0;
			capacity=capacity-weight[i];
			tp=tp+profit[i];
		}
		else {break;}
	}
	if(capacity>0){
		x[i]=capacity/weight[i];
		tp=tp+(ratio[i]*capacity);
	}
	cout<<"the resultant vector is ";
	print(x,n);
	cout<<"the profit is "<<tp;
}

int main(){
	float profit[20];
	float weight[20];
	float ratio[20];
	int n,capacity;
	cout<<"enter the no of objects ";
	cin>>n;
	cout<<"enter the capacity of the knapsack ";
	cin>>capacity;
	for(int i=0;i<n;i++){
		cout<<"enter the profits of object "<<i+1<<" ";
		cin>>profit[i];
		cout<<"enter the weight of object "<<i+1<<" ";
		cin>>weight[i];
	}
	for(int i=0;i<n;i++){
		ratio[i]=profit[i]/weight[i];
	}
	cout<<endl;
	print(ratio,n);
	/*sort(ratio,ratio+n,greater<float>());
	print(ratio,n);*/
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(ratio[i]<ratio[j]){
				swap(ratio[i],ratio[j]);
				swap(profit[i],profit[j]);
				swap(weight[i],weight[j]);
			}
		}
	}
	knapsack(n,capacity,profit,weight,ratio);
}
