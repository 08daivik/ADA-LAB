#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void heapify(int *arr,int n,int root)
{
    int largest=root;
    int l= (2*root)+1;
    int r=(2*root)+2;

    if(l<n)
    {
        if(arr[l] > arr[largest])
            largest=l;
    }
    
    if(r<n)
    {
        if(arr[r] > arr[largest])
            largest=r;
    }

    if(largest!=root)
    {
        swap(&arr[largest],&arr[root]);
        heapify(arr,n,largest);
    }
}

void heapsort(int *arr,int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

void main()
{
    int n;
    int *arr;
    printf("Enter the size of array");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Array before sorting\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    heapsort(arr,n);

    printf("\nArray after sorting\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);    
    printf("\n");
    free(arr);
}


