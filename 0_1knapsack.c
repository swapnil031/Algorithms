#include<stdio.h>

int max(int a,int b){
    a>b?a:b;
}

void knapsack(int profit[],int wt[],int W,int n){
    int k[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0)
                k[i][w]=0;
            else if(wt[i-1]<=w)
                k[i][w]=max(profit[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
            else
                k[i][w]=k[i-1][w];
        }
    }
    printf("the max value in the khapsack is %d",k[n][W]);
}
int main(){
    int profit[]={1,2,5,6};
    int wt[]={2,3,4,5};
    int capacity=8;
    int n=sizeof(profit)/sizeof(profit[0]);
    knapsack(profit,wt,capacity,n);
}