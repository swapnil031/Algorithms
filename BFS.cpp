#include <stdio.h>

#define MAX 50
int front=-1;
int rear=-1;
int adjacencyM[MAX][MAX];
int Queue[MAX];
int visited[MAX];
int n;

void enqueue(int a){
	/* 
	! if(rear==n-1 || front>rear){
	!	return;
	}
	*/
	if(front==-1){
		front++;
	}
	Queue[++rear]=a;
}

int dequeue(){
	int item=Queue[front];
	front++;
	return item;
}

void bfs(int n,int start_node){
	int current_node;
	enqueue(start_node);
	visited[start_node]=1;
	while(front<=rear){
		current_node=dequeue();
		printf("%d -> ",current_node);
		for(int i=0;i<n;i++){
			if(adjacencyM[current_node][i] && !visited[i]){
				enqueue(i);
				visited[i]=1;
			}
		}
	}
	printf("end");
}

int main()
{
	FILE *fp=fopen("ip.txt","r");
	fscanf(fp,"%d",&n);
	printf("%d \n",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&adjacencyM[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",adjacencyM[i][j]);
		}
		printf("\n");
	}
	int start_node;
	printf("enter the starting node : ");
	scanf("%d",&start_node);
	printf("The BFS traversal is ");
	bfs(n,start_node);
}
