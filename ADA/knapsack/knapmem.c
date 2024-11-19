#include<stdio.h>
#include<stdlib.h>

int knap[100][100],profit[100],wt[100];
int cap,item;
int opcount=0;

int max(int a,int b)
{
    return (a>b)?a:b;
}

int knapsack(int i,int j)
{
    if(knap[i][j]==-1)
    {
        opcount++;
        if(wt[i]>j)
        {
            knap[i][j]=knapsack(i-1,j);
        }
        else
            knap[i][j]=max((knapsack(i-1,j)),(profit[i]+knapsack(i-1,j-wt[i])));
    }
    return knap[i][j];
}

void run()
{
    printf("Enter number of items:\n");
    scanf("%d",&item);
    printf("Enter the capacity of knapsack:\n");
    scanf("%d",&cap);

    printf("Enter details\n");
    for(int i=1;i<=item;i++)
    {
        printf("Item %d\n",i);
        printf("Enter weight : ");
        scanf("%d",&wt[i]);
        printf("\nEnter profit : ");
        scanf("%d",&profit[i]);
    }

    for(int i=0;i<=item;i++)
        for(int j=0;j<=item;j++)
        {
            if(i==0 || j==0)
                knap[i][j]=0;
            else
                knap[i][j]=-1;
        }

    printf("\nMaximum profit = %d\n",knapsack(item,cap));

    printf("Knap table\n");
    for(int i=0;i<=item;i++)
    {
        for(int j=0;j<=item;j++)
        printf("%d\t",knap[i][j]);
    printf("\n");
    }        

    int w=cap;
    printf("Composition\n");
    for(int i=item;i>0;i--)
    {
        if(knap[i][w]!=knap[i-1][w])
            printf("%d\t",i);
    }
    printf("\n");
}

void main()
{
    run();
    printf("Operation count = %d\n",opcount);
}