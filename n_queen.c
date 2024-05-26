#include<stdio.h>
#include<math.h>
int n,count=0;
int x[15];
void print()
{
    int i,j;
    printf("\n\nthe coloumns vector is\n\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d\t",x[i]);
    }
    printf("\n\nSolution %d:\n\n",++count);
    for(i=1;i<=n;i++)
    {
        printf("\t%d",i);
    }
    for(i=1;i<=n;i++)
    {
        printf("\n\n%d",i);
        for(j=1;j<=n;j++)
        {
            if(x[i]==j)
                printf("\tQ");
            else
                printf("\t0");
        }
    }
}
int is_safe(int k,int i)
{
    for(int j=1;j<=k-1;j++)
    {
        if(x[j]==i || (fabs(x[j]-i)==fabs(k-j)))
        {
            return 0;
        }
    }
    return 1;
}
void nqueen(int k,int n)
{
    for(int col=1;col<=n;col++)
    {
        if(is_safe(k,col))
        {
            x[k]=col;
            if(k==n)
            {
                print();
            }
            else
            {
                nqueen(k+1,n);
            }
        }
    }
}
int main()
{
    printf("Enter the number of queens:");

    scanf("%d",&n);
    nqueen(1,n);
    if(n==2 || n==3)
        printf("not possible");
    return 0;
}