#include<stdio.h>
    
    void msort(int a[],int lb,int ub)
{
    int m;
    if(lb<ub)
    {
        m=(lb+ub)/2;
        msort(a,lb,m);
        msort(a,m+1,ub);
        merge(a,lb,m,ub);
    }
}
    void merge(int a[],int lb,int m,int ub)
    {
        int b[50];
        int i=lb,j=m+1,k=lb;
        while (i<=m && j<=ub)
        {
            if(a[i]<=a[j])
            {
                b[k]=a[i];
                k++;
                i++;
            }
            else
            {
                b[k]=a[j];
                k++;
                j++;
            }
        }
        while(i<=m)
        {
            b[k]=a[i];
            k++;
            i++;
        }
        while(j<=ub)
        {
            b[k]=a[j];
            k++;
            j++;
        }
        //printf("after sorting the array is:  ");
        for(i=lb,k=lb;i<=ub,k<=ub;i++,k++)
        {
           a[i]=b[k];
        }
    }


void printArray(int a[], int n) 
{
  for (int i = 0; i <n; i++)
        printf("%d ", a[i]);
  printf("\n");
}
int main()
{
    int a[50];
    int i,j,l,b,n;
    printf("\nenter the size of the array:\n");
    scanf("%d",&n);
    printf("enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("the entered elements are:");
    for(i=0;i<n;i++)
        printf(" %d",a[i]);
    msort(a,0,n-1);
    printf("\nSorted array: \n");
    printArray(a,n);
}