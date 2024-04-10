#include<stdio.h>

void printjobs(int profit[],int deadline[],int n){
	for(int i=0;i<n;i++){
		printf("Job %d    profit %d    deadline %d",i+1,profit[i],deadline[i]);
		printf("\n");
	}
	printf("\n");
}
void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void bubblesort(int profit[],int deadline[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(profit[j+1]>profit[j]){
				swap(&profit[j],&profit[j+1]);
				swap(&deadline[j],&deadline[j+1]);
			}
		}
	}
}
void jobseq(int profit[],int deadline[],int n){
	
	bubblesort(profit,deadline,n);
	printjobs(profit,deadline,n);
	int result[50];// for job sequence purpose
	int slots[50]={0};
	int maxprofit;
	for (int i = 0; i < n; i++) { // here we are considering all the jobs
        for (int j = deadline[i] - 1; j >= 0; j--) {
            if (slots[j] ==0) {
                slots[j] = 1;
				result[j]=i;
				maxprofit+=profit[i];
                break;
            }
        }
    }
	printf("As per the new job sequence based on the maximum profit, the sequence is ");
	for(int i=0;i<n;i++){
		if(slots[i]==1){
			printf("%d ",result[i]+1);
		}
	}
	printf("\n");
	printf("the maximum profit is %d",maxprofit);
}

int main(){
	int profit[50],deadline[50],n;
	printf("enter the no of jobs ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter the profit of job %d ",i+1);
		scanf("%d",&profit[i]);
		printf("Enter the deadline of job %d ",i+1);
		scanf("%d",&deadline[i]);
	}
	printjobs(profit,deadline,n);
	jobseq(profit,deadline,n);
}