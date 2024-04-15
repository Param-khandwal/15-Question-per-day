#include<stdio.h>
void merge(int a[],int l,int m,int r)
{
	int b[50];
	int i,j,k;
	i=l;
	j=m+1;
	k=l;
	while(i<=m&&j<=r)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	if(i>m)
	{
		while(j<=r)
			b[k++]=a[j++];
	}
	else
	{
		while(i<=m)
			b[k++]=a[i++];
	}
	for(i=l;i<=r;i++)
		a[i]=b[i];
}
void mergesort(int a[],int l,int r)
{
	int m;
	if(l<r)
	{
		m=(l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}
int main()
{
	int i,n;
	printf("Enter array size\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Before sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	mergesort(a,0,n-1);
	printf("\nAfter sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
