#include<stdio.h>
int main()
{
	int i,j,m,n,o,p,max,c;
	int a[10];
	printf("Enter the no of digits:");
	scanf("%d",&n);
	printf("Enter the numbers:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[max])
			{
				max=j;
			}
		//if(max!=i)
		
		c=a[i];
		a[i]=a[max];
		a[max]=c;
		
		}
		
		//printf("%d ",a[max]);
	}
	printf("After sorting the array is:");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
