#include<stdio.h>
int main()
{
    int a[20];
    int n,j,i,m;
    printf("enter the no of elements: ");
    scanf("%d",&n);
    printf("enter the elements");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("after sorting the array is ");
    for(i=0;i<n;i++)
        printf("%d",a[i]);
}